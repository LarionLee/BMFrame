//
//  BMModel.h
//  BMTalk
//
//  Created by lixinmin on 15/8/19.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BMModel : NSObject

#pragma mark - Init methods

/**
 *  获取所有已缓存的实体对象
 *
 *  @return 对象数组
 */
- (NSArray *)cachedEntities;

/**
 *  便利构造器
 *
 *  @return 实体对象
 */
+ (id)model;

/**
 *  初始化方法
 *
 *  @param domain       model对应的请求路径
 *  @param entityClass  model对应的数据类型（传空底层不会统一处理，直接返回JSON解析之后的数据）
 *
 *  @return model实体
 */
- (instancetype)initWithDomain:(NSString *)domain entity:(Class)entityClass;

/**
 拉取服务端数据

 @param params   model对应的请求参数
 @param sHandler 成功的回调
 @param fHandler 失败的回调
 */
- (void)requestEntitiesWithParams:(NSDictionary *)params
                          success:(void(^)(id entities))sHandler
                             fail:(void(^)(NSString *errorMsg))fHandler;

#pragma mark - Delete methods

/**
 *  单个数据删方法
 *
 *  @param entity 要删除的实体对象
 */
- (void)deleteEntity:(id)entity;

/**
 *  按条件删除对象
 *
 *  @param paramDict 检索参数字典 例：
 *  @{
 *      @"key1":@"value1",
 *      @"key2":@"value2",
 *      @"key3":@"value3"
 *      ...
 *  }
 */
- (void)deleteEntityMatchParams:(NSDictionary *)paramDict;

/**
 *  数据清空方法
 */
- (void)deleteAllEntiyies;

#pragma mark - Fetch methods

/**
 *  按条件删除对象
 *
 *  @param paramDict 检索参数字典 例：
 *  @{
 *      @"key1":@"value1",
 *      @"key2":@"value2",
 *      @"key3":@"value3"
 *      ...
 *  }
 */
- (NSArray *)fetchEntitiesMatchParams:(NSDictionary *)paramDict;

/**
 *  查询该类的所有实体对象
 *
 *  @return 查询结果
 */
- (NSArray *)fetchAllEntities;

/**
 *  撤销由Model发起的正在执行的网络请求
 */
- (void)cancelRequest;

@end
