//
//  UIViewController+HZURLManager.h
//  ZHFramework
//
//  Created by xzh. on 15/8/21.
//  Copyright (c) 2015年 xzh. All rights reserved.
//
/**
 *  根据URL生成控制器
 */

#import <UIKit/UIKit.h>
@interface UIViewController (HZURLManager)

/** controller所对应的URL */
@property(nonatomic, strong, readonly) NSString *ctrlURL;

/** 参数字典,由查询字符串和跳转时传入的NSDictionary组成 */
@property(nonatomic, strong, readonly) NSDictionary *paramDic;

/**
 *	根据URL(schema://abc?k=v)创建对应的控制器
 *
 *	@param URLString  与想要创建的控制器对应的URL字符串
 *  @param paramDic   传给想要创建的控制器的字典,可通过paramDic获取
 */
+ (UIViewController *)viewControllerWithString:(NSString *)URLString;
+ (UIViewController *)viewControllerWithString:(NSString *)URLString paramDic:(NSDictionary *)paramDic;

@end
