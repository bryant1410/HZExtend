//
//  HZURLManageConfig.h
//  HZNetworkDemo
//
//  Created by xzh on 16/2/27.
//  Copyright © 2016年 xzh. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HZSingleton.h"
/**
 *  URLManager中的数据配置器
 */
@interface HZURLManagerConfig : NSObject
singleton_h(Config)

/** URL:Ctrl配置字典 */
@property(nonatomic, strong) NSDictionary *URLCtrlConfig;

/** URL重写配置表 */
@property(nonatomic, copy, readonly) NSDictionary *URLRewriteConfig;

/** http(s)URL对应的默认Ctrl,配置表无http(s)URL对应ctrl时默认会创建该Ctrl */
@property(nonatomic, strong) NSString *classOfWebViewCtrl;

/** 跳转时是否隐藏下bar,默认NO */
@property(nonatomic, assign) BOOL hideBottomWhenPushed;

/**
 *	追加URL重写配置表
 *
 *	@param URLRewriteConfig  需要追加的URL重写配置表
 */
- (void)appendURLRewriteConfig:(NSDictionary *)URLRewriteConfig;

@end
