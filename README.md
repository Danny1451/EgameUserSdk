# EgameUserSDK


## 一、 快速配置

EgameUserSDK支持使用Cocoapods集成

在pod中加入以下语句

    pod 'EgameUserSDK', '~> 1.1.1'


## 二、 配置URL Schemes

打开Target的Info选项卡，找到URL Types并添加一个新项，Identifier为EgameUser，URL Schemes为自定义，建议为产品英文名字+EgameUser(不支持下划线等特殊字符)，如下图所示

![配置URL Schemes][1]

## 三、 调用登录方法

调用登录代码主要分为以下步骤：

 - 1）导入头文件：在需要调用登录代码的文件中导入以下头文件
 


```Object-c
    #import “EgameUserSdk.h”
```


 - 2）设置游戏参数：在需要调用登录代码的文件中设置游戏参数 
 

```Object-c
    必要参数为游戏的Client_id
    
    //游戏的Client_Id
    #define CLIENT_ID  @"30681631"

```

 - 3）获取SDK的单例并调用SDK的startWithClientId方法并处理登录结果


```Object-c

    [[[EgameUserSdk shareInstance] startWithClientId:CLIENT_ID
                                            callback:^(EgameResult result,
                                                        NSString *ssoCode, 
                                                        int failedReason) {
            // 处理结果
            NSLog(@"The sso code: %@", ssoCode);
            NSLog(@"The result: %d", result);
            NSLog(@"The failed reason: %d", failedReason);
    }];
```

    先判断EgameResult的result值。 
    SUCCESS: 登录成功，ssoCode为授权码，CP可以用来换取token。 
    FAILED:  登录失败，failedReason为错误码，可在附录I中查询。 
    CANCEL:  登陆取消，用户取消登陆。



- 4）登录成功后根据授权码在有效时间内请自行换取token

----------

##服务端接入

请见详细文档 


##客户端错误代码
|错误代码 | 错误信息 |
|-------  :| ------ :|
|0|无错误|
|-10|登录失败|
|-11|重定向失败|
|-100|服务器异常|
|-276|密码错误次数过多|
|-1004|网络异常|


##Q&A

>1.	移动和联通的手机号可以注册吗？
可以。
>2.	为什么调用爱游戏授权码兑换令牌接口时，虽然做了签名，但是仍跑不通？
首先确定请求头里包含编码格式信息：
Content-Type = application/x-www-form-urlencoded
然后确定请求体里的参数已经做过UrlEcode处理，即参数值里包含的“&”等特殊字符已经转义。
如果按照以上方法仍无法跑通，请尝试把请求参数直接拼到url后面，而不是放到请求体里，如下图所示：
![此处输入图片的描述][2]
如果报错信息与图中一致，恭喜你，接口已经调通了，换一个正确的code即可。
>3.	为什么做签名时，要把签名转换成16进制字符串？
因为MD5加密后的签名为byte数组，传输时需转换成对应字符串

>4. 为什么我的网游服务端配置没有问题但是却拿不到客户端请求的数据？
因为虽然客户端重定向到网游服务端的提交方式是post，但是请求参数是拼接在url地址上的

>5. 如何验证我的数字签名MD5算法是否与爱游戏一致？
可用您的MD5算法对如下串进行加密：
1421986517277MD5abc2d0c88900417c88e4f6d678c6d04f111111112.1.0
正确结果：4066426956C959ECBC84597786428313

>6. 升级iOS9.0 之后无法登陆？
   因为iOS9.0中的网络安全ATS 要求，导致SDK中的部分接口失效，目前解决方案如下。
你可以在Info.plist 配置中改用下面的XML源码：
```
<key>NSAppTransportSecurity</key>
<dict>
<key>NSAllowsArbitraryLoads</key>
</true>
</dict>
```
在 plist 文件里显示如下：
![此处输入图片的描述][3]


  [1]: https://raw.githubusercontent.com/Danny1451/EGUserSDK/master/Doc/picture1.png
  [2]: https://raw.githubusercontent.com/Danny1451/EGUserSDK/master/Doc/picture3.png
  [3]: https://raw.githubusercontent.com/Danny1451/EGUserSDK/master/Doc/picture2.png
