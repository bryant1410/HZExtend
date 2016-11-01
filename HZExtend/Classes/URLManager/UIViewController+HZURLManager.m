//
//  UIViewController+HZURLManager.m
//  ZHFramework
//
//  Created by xzh. on 15/8/21.
//  Copyright (c) 2015年 xzh. All rights reserved.
//

#import "UIViewController+HZURLManager.h"

#import "NSURL+HZExtend.h"
#import "NSObject+HZExtend.h"
#import "NSString+HZExtend.h"

#import "HZURLManageConfig.h"

#import <objc/runtime.h>

static const char kCtrlURL = '\0';
static const char kParamDic = '\1';
@interface UIViewController ()

@property(nonatomic, strong) NSString *ctrlURL;
@property(nonatomic, strong) NSDictionary *paramDic;

@end

@implementation UIViewController (HZURLManager)

#pragma mark - Public Method
+ (UIViewController *)viewControllerWithString:(NSString *)URLString
{
    return [self viewControllerWithString:URLString paramDic:nil];
}

+ (UIViewController *)viewControllerWithString:(NSString *)URLString paramDic:(NSDictionary *)paramDic
{
    NSString *scheme = URLString.scheme;
    NSDictionary *config = [HZURLManageConfig sharedConfig].config;
    if (!URLString.isNoEmpty || !config.isNoEmpty) return nil;
    
    /*******************根据schema创建控制器********************/
    UIViewController *viewCtrl = nil;
    if ([scheme isEqualToString:@"http"]||[scheme isEqualToString:@"https"]) {  //schema为http
        NSString *strWebCtrl = [HZURLManageConfig sharedConfig].classOfWebViewCtrl.isNoEmpty?[HZURLManageConfig sharedConfig].classOfWebViewCtrl:@"HZWebViewController";
        Class class = NSClassFromString(strWebCtrl);
        viewCtrl = [[class alloc] initWithURL:[NSURL URLWithString:URLString]];
    }else { //shchema为自定义
        NSString *strclass = [config objectForKey:URLString.allPath];
        NSString *errorInfo = nil;
        if(strclass.isNoEmpty) {
            Class class = NSClassFromString(strclass);
            if(NULL != class) {
                viewCtrl = [[class alloc] init];
            }else { //无该控制器
                errorInfo = [NSString stringWithFormat:@"404 :) ,%@并无注册",strclass];
            }
        }else {//无该URL
            errorInfo = [NSString stringWithFormat:@"404 :) ,%@://%@并无注册",URLString.scheme,URLString.host];
        }
        
#ifdef DEBUG  // 调试状态
        viewCtrl = viewCtrl?:[self errorViewConrtollerWithInfo:errorInfo];
        
#else // 发布状态
#endif
    }
    
    if (viewCtrl) {
        NSMutableDictionary *tmpDic = [NSMutableDictionary dictionary];
        NSDictionary *urlQueryDic = URLString.queryDic;
        if (urlQueryDic.isNoEmpty) [tmpDic addEntriesFromDictionary:urlQueryDic];
        if (paramDic.isNoEmpty) [tmpDic addEntriesFromDictionary:paramDic];
        viewCtrl.paramDic = tmpDic;
        viewCtrl.ctrlURL = URLString;
    }
    
    return viewCtrl;
}

#pragma mark Private Method
/**
 *  创建错误控制器
 */
#ifdef DEBUG
+ (UIViewController *)errorViewConrtollerWithInfo:(NSString *)errorInfo
{
    Class noCtrlClass = NSClassFromString(@"HZErrorViewController");
    UIViewController *viewCtrl = [[noCtrlClass alloc] init];
    [viewCtrl setValue:errorInfo forKey:@"errorInfo"];
    return viewCtrl;
}
#endif

#pragma mark - Property
- (void)setCtrlURL:(NSString *)ctrlURL
{
    NSString *url = objc_getAssociatedObject(self, &kCtrlURL);
    if (url != ctrlURL) {
        [self willChangeValueForKey:@"ctrlURL"];
        objc_setAssociatedObject(self, &kCtrlURL, ctrlURL, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        [self didChangeValueForKey:@"ctrlURL"];
    }

}

- (NSString *)ctrlURL
{
    return objc_getAssociatedObject(self, &kCtrlURL);
}

- (void)setParamDic:(NSDictionary *)paramDic
{
    NSDictionary *dic = objc_getAssociatedObject(self, &kParamDic);
    if (dic != paramDic) {
        [self willChangeValueForKey:@"paramDic"];
        objc_setAssociatedObject(self, &kParamDic, paramDic, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
        [self didChangeValueForKey:@"paramDic"];
    }
    
}

- (NSDictionary *)paramDic
{
    return objc_getAssociatedObject(self, &kParamDic);
}


@end
