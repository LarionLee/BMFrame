//
//  BMRequest.m
//  BMModel
//
//  Created by lixinmin on 15/11/6.
//  Copyright © 2015年 &#30334;&#24230;&#22312;&#32447;. All rights reserved.
//

#import "BMRequest.h"
#import "BMUrlMaker.h"
#import <AFNetworking/AFNetworking.h>

static AFHTTPSessionManager *sessionManager;
static BMRequest *shareInstance;

@interface BMRequest ()

@property (nonatomic) dispatch_source_t syncStepOverSource;
@property (nonatomic) dispatch_queue_t syncQueue;
@property (nonatomic, strong) NSMutableDictionary *runningRequests;

@end

@implementation BMRequest

#pragma mark - public methods

+ (void)load {
    static dispatch_once_t  onceToken;
    dispatch_once(&onceToken, ^{
        shareInstance = [[BMRequest alloc] init];
        
        NSURLSessionConfiguration * config = [NSURLSessionConfiguration defaultSessionConfiguration];
        config.timeoutIntervalForRequest = 8.0f;
        config.timeoutIntervalForResource = 60.0f;
        sessionManager = [[AFHTTPSessionManager alloc] initWithSessionConfiguration:config];
    });
}

+ (void)getDomain:(NSString *)domain
           params:(NSDictionary *)paramDict
          success:(void (^)(id))sHandler
             fail:(void (^)(NSString *))fHandler
            group:(NSString *)groupId {
    NSURLSessionDataTask *getTask = [sessionManager GET:[BMUrlMaker commonUrlWithDomain:domain params:paramDict]
                                             parameters:nil
                                                success:^(NSURLSessionDataTask * _Nonnull task, id  _Nonnull responseObject) {
                                                    [shareInstance releaseRequestTask:getTask withGroupID:groupId];
                                                    if (![@0 isEqual:[responseObject valueForKey:@"status"]]) {
                                                        // 状态码不为0，返回错误信息
                                                        if (fHandler) {
                                                            fHandler([responseObject valueForKey:@"statusInfo"]);
                                                        }
                                                    } else {
                                                        if (sHandler) {
                                                            sHandler([responseObject valueForKey:@"data"]);
                                                        }
                                                    }
                                                }
                                                failure:^(NSURLSessionDataTask * _Nonnull task, NSError * _Nonnull error) {
                                                    [shareInstance releaseRequestTask:getTask withGroupID:groupId];
                                                    if (fHandler) {
                                                        // failHandler(TIP_FAILMESSAGR);
                                                        fHandler(error.localizedDescription);
                                                    }
                                                }];
    [shareInstance holdRequestTask:getTask withGroupID:groupId];
}

+ (void)postDomain:(NSString *)domain
            params:(NSDictionary *)paramDict
           success:(void (^)(id))sHandler
              fail:(void (^)(NSString *))fHandler
             group:(NSString *)groupId {
    NSMutableDictionary *mDict = [NSMutableDictionary dictionaryWithDictionary:[BMUrlMaker commonParamDict]];
    if (paramDict) {
        [mDict addEntriesFromDictionary:paramDict];
    }
    
    NSURLSessionDataTask *postTtask = [sessionManager POST:[BMUrlMaker urlWithDomain:domain params:nil]
                                                parameters:mDict
                                                   success:^(NSURLSessionDataTask * _Nonnull task, id  _Nonnull responseObject) {
                                                       [shareInstance releaseRequestTask:postTtask withGroupID:groupId];
                                                       if (![@0 isEqual:[responseObject valueForKey:@"status"]]) {
                                                           // 状态码不为0，返回错误信
                                                           if (fHandler) {
                                                               fHandler([responseObject valueForKey:@"statusInfo"]);
                                                           }
                                                       } else {
                                                           if (sHandler) {
                                                               sHandler([responseObject valueForKey:@"data"]);
                                                           }
                                                       }
                                                   }
                                                   failure:^(NSURLSessionDataTask * _Nonnull task, NSError * _Nonnull error) {
                                                       [shareInstance releaseRequestTask:postTtask withGroupID:groupId];
                                                       if (fHandler) {
                                                           // failHandler(TIP_FAILMESSAGR);
                                                           fHandler(error.localizedDescription);
                                                       }
                                                   }];
    [shareInstance holdRequestTask:postTtask withGroupID:groupId];
}

+ (void)uploadDomain:(NSString *)domain
              params:(NSDictionary *)paramDict
           dataArray:(NSArray *)dataArray
             success:(void(^)(id response))sHandler
                fail:(void(^)(NSString *errorMsg))fHandler
               group:(NSString *)groupId {
    NSMutableDictionary *mDict = [NSMutableDictionary dictionaryWithDictionary:[BMUrlMaker commonParamDict]];
    if (paramDict) {
        [mDict addEntriesFromDictionary:paramDict];
    }
    
    NSURLSessionDataTask *postTtask = [sessionManager POST:[BMUrlMaker urlWithDomain:domain params:nil]
                                                parameters:mDict
                                 constructingBodyWithBlock:^(id<AFMultipartFormData>  _Nonnull formData) {
                                     if (dataArray && [dataArray isKindOfClass:[NSArray class]]) {
                                         [dataArray enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                                             if ([obj isKindOfClass:[NSDictionary class]]) {
                                                 [formData appendPartWithFileData:obj[@"data"] name:obj[@"name"] fileName:obj[@"fileName"] mimeType:obj[@"mimeType"]];
                                             }
                                         }];
                                     }
                                 }
                                                   success:^(NSURLSessionDataTask * _Nonnull task, id  _Nonnull responseObject) {
                                                       [shareInstance releaseRequestTask:postTtask withGroupID:groupId];
                                                       if (![@0 isEqual:[responseObject valueForKey:@"status"]]) {
                                                           // 状态码不为0，返回错误信
                                                           if (fHandler) {
                                                               fHandler([responseObject valueForKey:@"statusInfo"]);
                                                           }
                                                       } else {
                                                           if (sHandler) {
                                                               sHandler([responseObject valueForKey:@"data"]);
                                                           }
                                                       }
                                                   }
                                                   failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
                                                       [shareInstance releaseRequestTask:postTtask withGroupID:groupId];
                                                       if (fHandler) {
                                                           // failHandler(TIP_FAILMESSAGR);
                                                           fHandler(error.localizedDescription);
                                                       }
                                                   }];
    [shareInstance holdRequestTask:postTtask withGroupID:groupId];
}

+ (void)cancelRequests:(NSString *)groupId {
    NSArray *array = [[shareInstance runningRequests] objectForKey:groupId];

    if (array) {
        [array enumerateObjectsUsingBlock:^(NSURLSessionDataTask *task, NSUInteger idx, BOOL * _Nonnull stop) {
            [task cancel];
        }];
    }
}

#pragma mark - private methods

- (void)holdRequestTask:(NSURLSessionDataTask *)task withGroupID:(NSString *)groupId {
    NSMutableArray *array = [self.runningRequests objectForKey:groupId];
    
    if (!array) {
        array = [NSMutableArray array];
        [self.runningRequests setObject:array forKey:groupId];
    }
    
    [array addObject:task];
}

- (void)releaseRequestTask:(NSURLSessionDataTask *)task withGroupID:(NSString *)groupId {
    NSMutableArray *array = [self.runningRequests objectForKey:groupId];
    if (array) {
        [array removeObject:task];
    }
}

#pragma mark - dynamic methods

- (dispatch_source_t)syncStepOverSource{
    if (!_syncStepOverSource) {
        _syncStepOverSource = dispatch_source_create(DISPATCH_SOURCE_TYPE_DATA_ADD, 0, 0, dispatch_get_main_queue());
//        @weakify(self);
        dispatch_source_set_event_handler(_syncStepOverSource, ^{
//            @strongify(self);
        });
        dispatch_resume(_syncStepOverSource);
    }
    
    return _syncStepOverSource;
}

- (dispatch_queue_t)syncQueue{
    if (!_syncQueue) {
        _syncQueue = dispatch_queue_create("com.BMRequestSyncQueue.GCD", DISPATCH_QUEUE_SERIAL);
    }
    
    return _syncQueue;
}

- (NSMutableDictionary *)runningRequests {
    if (!_runningRequests) {
        _runningRequests = [NSMutableDictionary dictionary];
    }
    
    return _runningRequests;
}

@end
