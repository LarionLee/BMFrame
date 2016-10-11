//
//  BMModel.m
//  BMTalk
//
//  Created by lixinmin on 15/8/19.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import "BMModel.h"
#import "BMUrlMaker.h"
#import "BMRequest.h"
#import <objc/runtime.h>

static const void *propertyListKey = &propertyListKey;

@interface BMModel (){
    NSMutableArray *_entityArray;
}

// Model info
@property (nonatomic, strong) NSString *domain;
@property (nonatomic, strong) Class entityClass;

@end

@implementation BMModel

#pragma mark - init methods

+ (BMModel *)model {
    return [[self alloc] initWithDomain:nil entity:[NSObject class]];
}

- (instancetype)initWithDomain:(NSString *)domain entity:(Class)entityClass {
//    // 初始化CoreData（只执行一次）
//    static dispatch_once_t  onceToken;
//    dispatch_once(&onceToken, ^{
//        [NSManagedObject setupCoreData];
//    });

    self = [super init];
    
    if (self) {
        self.domain = domain;
        self.entityClass = entityClass;
        // 初始化完成 主动刷新本地数据
        [self fetchAllEntities];
    }
    
    return self;
}

#pragma mark - Request methods

- (void)requestEntitiesWithParams:(NSDictionary *)params
                          success:(void(^)(id))sHandler
                             fail:(void(^)(NSString *))fHandler {
    @weakify(self);
    [BMRequest getDomain:self.domain
                  params:params
                 success:^(id response) {
                     @strongify(self);
                     
                     if (sHandler) {
//                         sHandler([self serializeJSONData:response]);
                     }
                 }
                    fail:fHandler
                   group:NSStringFromClass([self class])];
}

#pragma mark - Cache methods

- (NSArray *)cachedEntities {
    // TO DO: Need Time To Finish
    return nil;
//    return [self.entityClass cachedEntities];
}

- (void)deleteEntity:(id)entity {
//    return [entity deleteFromCache];
}

- (void)deleteEntityMatchParams:(NSDictionary *)paramDict {
//    return [self.entityClass deleteEntityMatchParams:paramDict];
}

- (void)deleteAllEntiyies {
//    return [self.entityClass deleteAllEntiyies];
}

- (NSArray *)fetchEntitiesMatchParams:(NSDictionary *)paramDict {
    // TO DO: Need Time To Finish
    return nil;
//    return [self.entityClass fetchEntitiesMatchParams:paramDict];
}

- (NSArray *)fetchAllEntities {
    // TO DO: Need Time To Finish
    return nil;
//    return [self.entityClass fetchAllEntities];
}

-(void)cancelRequest {
    [BMRequest cancelRequests:NSStringFromClass([self class])];
}

#pragma mark - dynamic methods

- (NSArray *)entityArray {
    if (!_entityArray) {
        _entityArray = [NSMutableArray array];
    }
    
    return _entityArray;
}

- (void)setEntityArray:(NSArray *)entityArray {
    _entityArray = [NSMutableArray arrayWithArray:entityArray];
}

@end
