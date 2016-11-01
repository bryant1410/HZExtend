//
//  HZURLManager.h
//  ZHFramework
//
//  Created by xzh. on 15/8/21.
//  Copyright (c) 2015年 xzh. All rights reserved.
//
/**
 *  根据URL跳转/调用模块方法来实现解耦
 */

#import <Foundation/Foundation.h>
#import "HZSingleton.h"
#import "HZURLNavigation.h"
#import "UIViewController+HZURLManager.h"
@class HZViewController;
@interface HZURLManager : NSObject







/**
 *  将viewController push到当前的导航控制器,若当前导航控制器为nil则什么也不做
 */
+ (UIViewController *)pushViewControllerWithString:(NSString *)urlstring animated:(BOOL)animated;
+ (UIViewController *)pushViewControllerWithString:(NSString *)urlstring queryDic:(NSDictionary *)query animated:(BOOL)animated;

/**
 *  将viewController present到当前的控制器上
 */
+ (UIViewController *)presentViewControllerWithString:(NSString *)urlstring animated:(BOOL)animated completion:(void (^)(void))completion;
+ (UIViewController *)presentViewControllerWithString:( NSString *)urlstring queryDic:(NSDictionary *)query animated:(BOOL)animated completion:(void (^)(void))completion;

/**
 *  1.若当前控制器的容器为导航控制器,则pop
 *  2.若当前控制器为模态视图控制器,则dismiss
 */
+ (void)dismissCurrentAnimated:(BOOL)animated;

@end
