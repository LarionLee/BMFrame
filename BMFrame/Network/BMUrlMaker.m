//
//  BMUrlMaker.m
//  BDProject
//
//  Created by zyf on 15/4/16.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import "BMUrlMaker.h"
#import <UIKit/UIKit.h>

#define MAIN_HOST @""

@implementation BMUrlMaker

+ (NSString *)commonParam {
    NSMutableString *paramStr = [NSMutableString string];
    [[self commonParamDict] enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull obj, BOOL * _Nonnull stop) {
        if (0 < paramStr.length) {
            [paramStr appendString:@"&"];
        }
        [paramStr appendFormat:@"%@=%@", key, obj];
    }];
    
    return paramStr;
}

+ (NSDictionary *)commonParamDict {
//    SAPILoginModel *model = [BMPassportManager loginInfo];//获取用户登录的信息
//    NSString *strBduss = @"";//用户登录后的sessionId
//    if (model) {
//        strBduss = model.bduss;
//    }
    
    return @{@"term":@"ios",
             @"from":@"doctor",
             @"role":@"doctor",
//             @"s":[[[NSString stringWithFormat:@"%ld%@", (long)[[NSDate date] timeIntervalSince1970]/100, HOST_TOKENTIME] md5String] lowercaseString],
             @"DI":[[UIDevice currentDevice].identifierForVendor UUIDString],
//             @"bduss":[BMPassportManager bduss],
             @"latitude":@0,
             @"longitude":@0,
             @"is_gps_open":@0,
             @"version":[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"],
             @"act_id":@0,
             @"pre_act_id":@0};
}

+ (NSString *)commonUrlWithDomain:(NSString *)domainString
                           params:(NSDictionary *)paramDict {
    return [self urlWithHost:MAIN_HOST
                      domain:domainString
                 commonParam:[BMUrlMaker commonParam]
                      params:paramDict];
}

+ (NSString *)urlWithDomain:(NSString *)domainString params:(NSDictionary *)paramDict {
    return [self urlWithHost:MAIN_HOST
                      domain:domainString
                 commonParam:nil
                      params:paramDict];
}

+ (NSString *)urlWithHost:(NSString *)hostString
                   domain:(NSString *)domainString
              commonParam:(NSString *)commonString
                   params:(NSDictionary *)paramDict {
    // Host address
    NSMutableString *urlString = [NSMutableString stringWithString:hostString];
    // Domain address
    if (domainString) {
        [urlString appendFormat:@"/%@", domainString];
    }
    
    [urlString appendString:@"?"];

    // Commom param string
    if (commonString) {
        [urlString appendString:commonString];
    }
    
    // Otner param string
    [paramDict enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [urlString appendFormat:@"&%@=%@", key, obj];
    }];
    
    return urlString;
}

@end
