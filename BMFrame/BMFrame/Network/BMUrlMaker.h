//
//  BMUrlMaker.h
//  BDProject
//
//  Created by zyf on 15/4/16.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

#define API_HOST                        @""
#define HOST_APPSTORE                   @"http://itunes.apple.com"      // AppStore
#define HOST_TOKENTIME                  @"IMPaS5W0rD"

#define TIP_FAILMESSAGR                 @"网络连接不可用，请稍后重试"

#pragma mark - 接口url

#define kServerTimeInterval             @"kServerTimeInterval"          // 服务器时间与客户端时间差

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝push消息＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_PUSTNOTICE_BIND             @"sam/user/bind"                // 设备绑定
#define URL_PUSTNOTICE_UNBIND           @"sam/user/unbind"              // 设备解绑
#define URL_REMIND_FETCH                @"sam/remind/fetch"             // 获取push消息数

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  认证  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_APPROVE_DOCTORSTATE_GET     @"sam/register/index"           // 登陆获取医生状态
#define URL_APPROVE_PERSONINFO_SUBMIT   @"sam/register/create"          // 提交个人姓名电话等信息
#define URL_APPROVE_DOCTORLIST_GET      @"sam/doctor/listfordoctor"     // 认领时是否有对应的医生信息
#define URL_APPROVE_DOCTORDETAIL_GET    @"sam/register/doctordetail"    // 查询医生信息
#define URL_APPROVE_DOCTOR_CLAIM        @"sam/register/claim"           // 认领医生
#define URL_APPROVE_IMAGE_UPLOAD        @"sam/register/saveimage"       // 上传图片
#define URL_APPROVE_DOCTORINFO_SUBMIT   @"sam/register/submit"          // 提交个人信息
#define URL_APPROVE_GOODAT_GET          @"sam/goodat/info"              // 擅长信息获取
#define URL_APPROVE_GOODAT_SUBMIT       @"sam/goodat/change"            // 擅长信息修改
#define URL_APPROVE_SUBMITINFO_GET      @"sam/register/submittedInfo"   // 查看已提交信息
#define URL_APPROVE_PHONENUM_CHECK      @"sam/register/phoneCheck"      // 手机号唯一性校验接口
#define URL_REGISTER_ENPHONE            @"sam/register/enphone"         // 认证中获取用户手机号
#define URL_APPROVE_APPOINTTIME_GET     @"sam/appointtime/info"         // 认证－设置出诊时间 获取
#define URL_APPROVE_APPOINTTIME_SUBMIT  @"sam/appointtime/change"       // 认证－设置出诊时间 设置

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝ 预开通 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_REGISTER_WORK               @"sam/register/addWork"         // 设置工作经历接口
#define URL_REGISTER_ISCLAIM            @"sam/register/isClaim"         // 查看医生类型（0：自主，1：认领）


// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  预约  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_APPOINTMENT_LIST            @"sam/appointment/list"
#define URL_APPOINTMENT_CHECK           @"sam/appointment/check"
#define URL_APPOINTMENT_LISTTIME        @"sam/appointment/listtime"


// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  患者  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_PATIENT_LIST                @"sam/dpatient/list"                // 患者列表接口
#define URL_PATIENT_TREATMENT_LIST      @"sam/treatmenthistory/list"        // 就诊病历列表接口
#define URL_PATIENT_TREATMENT_ADDNOTE   @"sam/treatmenthistory/addnote"     // 给病历添加备注接口
#define URL_PATIENT_SEND_REMIND         @"sam/treatmenthistory/sendnotice"  // 向患者发送提醒患者补全病历接口
#define URL_PATIENT_UNBIND              @"sam/dpatient/unbind"              // 患者解绑接口
#define URL_PATIENT_SM_SEND             @"sam/sm/send"                      // 手机号邀请患者接口
#define URL_PATIENT_EDUCATION_LIST      @"sam/peducation/list"              // 患教列表接口
#define URL_PATIENT_EDUCATION_SAVE      @"sam/peducation/modify"            // 患教修改接口
#define URL_PATIENT_EDUCATION_DELETE    @"sam/peducation/delete"            // 患教删除接口
#define URL_PATIENT_EDUCATION_SEND      @"sam/peducation/send"              // 患教发送接口
#define URL_COMMON_IMAGE_ADDIMG         @"sam/common/saveimage"             // 患教编辑图片保存接口
#define URL_PATIENT_MARK                @"sam/dpatient/mark"                // 新患者设置成已查看接口

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  评价  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_EVALUATION_LIST             @"sam/evaluation/listfordoctor"
#define URL_EVALUATION_REPLY            @"sam/evaluation/replyfordoctor"

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  消息  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

#define URL_NOTICE_LIST                 @"sam/notice/get"               // 获取消息列表
#define URL_NOTICE_DETAIL               @"sam/notice/detail"            // 获取消息详情
#define URL_NOTICE_SETREAD              @"sam/notice/setread"           // 设置已读
#define URL_NOTICE_DELETE               @"sam/notice/del"               // 删除消息
#define URL_HOTACTIVITY_LIST            @"sam/hotactivity/list"         // 热门活动列表

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝ “我的” ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_MYINFO_GET                  @"sam/doctor/baseinfo"          // 获取我的信息
#define URL_MYINFO_SUBMIT               @"sam/doctor/change"            // 修改我的信息
#define URL_H5WEB_PROXY                 @"sam/declaration/disclaimer"   // 医生用户协议（web页面）
#define URL_H5WEB_HELP                  @"sam/declaration/help"         // 关于百度医生（web页面）
#define URL_APPVERSION_GET              @"sam/declaration/appVersion"   // 获取版本信息
#define URL_APPOINTTIME_GET             @"sam/appointtime/timelist"     // 获取出诊时间
#define URL_APPOINTTIME_SUBMIT          @"sam/appointtime/savetime"     // 设置出诊时间
#define URL_INVITE_DOCTORLIST_GET       @"sam/yly/invitedlist"          // 医拉医－获取邀请列表
#define URL_SHARE_2PATIENT              @"wise/search/index"            // 医拉患－分享跟二维码扫描
#define URL_SHARE_2DOCTOR               @"wise/yly/activity"            // 医拉医－分享跟二维码扫描
#define URL_H5WEB_INVITEDOCTOR          @"wise/yly/index"               // 医拉医－获取活动首页
#define URL_H5WEB_GETPAPERQR            @"wise/ylh/home"                // 医拉患 - 获取纸质二维码页面

// ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝  其他  ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#define URL_TOAST_GET                   @"sam/toast/info"               // 获取通用的提示信息
#define URL_STARTACTIVITY_GET           @"sam/declaration/welcome"      // 获取启动活动页
#define URL_SUGGESTION_GET              @"sam/suggestion/get"           // 输入联想接口（暂时只支持医院名称联想）
#define URL_DECLARATION_WELCOM          @"sam/declaration/welcome"      // 时间戳校验
#define URL_CAPTCHA_GET                 @"sam/common/captcha"           // 获取验证码
#define URL_BANNERLIST_GET              @"sam/toast/banner"             // 获取Banner列表
#define URL_YLHTAG_GET                  @"sam/toast/ylhtag"              //医拉患活动说明页面

@interface BMUrlMaker : NSObject

/**
 *  获取公共参数
 *
 *  @return 公共参数字符串
 */
+ (NSString *)commonParam;

/**
 *  获取公共参数
 *
 *  @return 公共参数字典
 */
+ (NSDictionary *)commonParamDict;

/**
 *  创建默认Host的请求URL（附带公共参数）
 *
 *  @param domainString 路径
 *  @param paramDict    参数（字典类型）
 *
 *  @return 请求的URL(添加公共参数)
 */
+ (NSString *)commonUrlWithDomain:(NSString *)domainString
                           params:(NSDictionary *)paramDict;

/**
 *  创建标准Host的请求URL （不会附带公共参数）
 *
 *  @param domainString 路径
 *  @param paramDict    参数（字典类型）
 *
 *  @return 请求的URL(添加公共参数)
 */
+ (NSString *)urlWithDomain:(NSString *)domainString
                     params:(NSDictionary *)paramDict;

/**
 *  创建默认Host的请求URL
 *
 *  @param hostString   host地址
 *  @param domainString 路径
 *  @param commonString  公共参数字符串
 *  @param paramDict    参数（字典类型）
 *
 *  @return 请求的URL(添加公共参数)
 */
+ (NSString *)urlWithHost:(NSString *)hostString
                   domain:(NSString *)domainString
              commonParam:(NSString *)commonString
                   params:(NSDictionary *)paramDict;

@end
