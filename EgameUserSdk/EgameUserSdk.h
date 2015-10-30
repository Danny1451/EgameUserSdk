//
//  EgameUserSdk.h
//  EgameUserSdk
//
//  Created by 韩玮 on 15/6/4.
//  Copyright (c) 2015年 炫彩互动网络科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
    以下是用户SDK操作失败原因代码
 */
#define REASON_NO_ERROR 0
#define REASON_LOGIN_ERROR -10
#define REASON_SSO_ERROR -11
#define REASON_SERVER_ERROR -100
#define REASON_NET_ERROR -1004
#define REASON_PASSWORD_ERROR_TOO_MANY_TIMES -276
#define REASON_PASSWORD_FORMAT_ERROR -206

/**
    处理结果
 */
typedef enum {
    SUCCESS = 0,
    FAILED = -1,
    CANCEL = 1,
}EgameResult;

/**
 *  用户SDK回调
 *
 *  @param result       处理结果
 *  @param ssoCode      认证码
 *  @param failedReason 失败原因代码
 */
typedef void(^EgameCallbackBlock)(EgameResult result, NSString *ssoCode, int failedReason);

@interface EgameUserSdk : NSObject

/**
 *  获取实例
 *
 *  @return 用户SDK示例
 */
+ (id) shareInstance;


/**
 *  启动用户SDK
 *
 *  @param clientId 游戏clientId
 *  @param callback 结果回调
 */
- (void) startWithClientId: (NSString*) clientId
                  callback: (EgameCallbackBlock) callback;

@end
