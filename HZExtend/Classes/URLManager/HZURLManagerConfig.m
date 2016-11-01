//
//  HZURLManageConfig.m
//  HZNetworkDemo
//
//  Created by xzh on 16/2/27.
//  Copyright © 2016年 xzh. All rights reserved.
//

#import "HZURLManagerConfig.h"
@interface HZURLManagerConfig ()

@property(nonatomic, copy) NSMutableDictionary *mutableURLRewriteConfig;

@end

@implementation HZURLManagerConfig
singleton_m(Config)
- (instancetype)init
{
    self = [super init];
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        
    });
    return self;
}

- (NSDictionary *)URLRewriteConfig
{
    return self.mutableURLRewriteConfig;
}

- (NSMutableDictionary *)mutableURLRewriteConfig
{
    if (!_mutableURLRewriteConfig) {
        _mutableURLRewriteConfig = [NSMutableDictionary dictionary];
    }
    return _mutableURLRewriteConfig;
}

@end
