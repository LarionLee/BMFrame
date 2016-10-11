//
//  BMRequest.h
//  BMModel
//
//  Created by lixinmin on 15/11/6.
//  Copyright © 2015年 &#30334;&#24230;&#22312;&#32447;. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BMUrlMaker.h"

@interface BMRequest : NSObject

/**
 *  发起GET请求
 *
 *  @param domain       请求路径
 *  @param paramDict    附加参数（默认会添加公共参数）
 *  @param sHandler     成功的回调
 *  @param fHandler     失败的回调（包括网络出错、解析失败、server返回错误信息等情况）
 *  @param groupId      请求组标识（可用于撤销请求等操作）
 */
+ (void)getDomain:(NSString *)domain
           params:(NSDictionary *)paramDict
          success:(void(^)(id response))sHandler
             fail:(void(^)(NSString *errorMsg))fHandler
            group:(NSString *)groupId;

/**
 *  发起POST请求
 *
 *  @param domain       请求路径
 *  @param paramDict    附加参数（默认会添加公共参数）
 *  @param sHandler     成功的回调
 *  @param fHandler     失败的回调（包括网络出错、解析失败、server返回错误信息等情况）
 *  @param groupId      请求组标识（可用于撤销请求等操作）
 */
+ (void)postDomain:(NSString *)domain
            params:(NSDictionary *)paramDict
           success:(void(^)(id response))sHandler
              fail:(void(^)(NSString *errorMsg))fHandler
             group:(NSString *)groupId;

/**
 *  数据上传请求
 *
 *  @param domain    请求路径
 *  @param paramDict 附加参数（默认会添加公共参数）
 *  @param dataArray  上传的数据字典
 *          @[@{@"data":data,
 *            @"name":data,
 *            @"fileName":name,
 *            @"mimeType":type
 *          }
 *  @param sHandler  成功的回调
 *  @param fHandler  失败的回调（包括网络出错、解析失败、server返回错误信息等情况）
 *  @param groupId   请求组标识（可用于撤销请求等操作）
 */
+ (void)uploadDomain:(NSString *)domain
              params:(NSDictionary *)paramDict
           dataArray:(NSArray *)dataArray
             success:(void(^)(id response))sHandler
                fail:(void(^)(NSString *errorMsg))fHandler
               group:(NSString *)groupId;

/**
 *  撤销请求
 *
 *  @param groupId 请求所属组Id
 */
+ (void)cancelRequests:(NSString *)groupId;

@end
