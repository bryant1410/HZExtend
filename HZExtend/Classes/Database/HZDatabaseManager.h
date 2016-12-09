//
//  HZDatabaseManager.h
//  Pods
//
//  Created by xzh on 2016/12/8.
//
//
/****************     操作和管理APP数据库     ****************/

#import <Foundation/Foundation.h>
#import "HZSingleton.h"

#define HZDBManager [HZDatabaseManager sharedManager]

NS_ASSUME_NONNULL_BEGIN

@interface HZDatabaseManager : NSObject
singleton_h(Manager)

/** 数据库存放路径 */
@property(nonatomic, copy, nullable) NSString *dbPath;

/**
 *  是否由receiver来管理连接
 *  默认为YES,在app活跃的生命周期则会一直保持连接,进入后台后会释放连接
 */
@property(nonatomic, assign) BOOL shouldControlConnection;

/**
 * 打开数据库
 *
 *  @return YES表示打开成功
 */
- (BOOL)open;

/**
 *  关闭数据库
 *  如果shouldControlConnection = YES,则会不起作用
 *  @return YES表示打开成功
 */
- (BOOL)close;

/**
 *  执行除查询以外的SQL语句
 *  需先使用‘open’来打开数据库
 *
 *	@param sql  sql语句,参数用?占位
 *  @param data 参数数组
 *
 *  @return YES表示执行成功
 */
- (BOOL)executeUpdate:(NSString *)sql withParams:(nullable NSArray *)data;

/**
 *  执行查询SQL语句
 *  需先使用‘open’来打开数据库
 *
 *	@param sql  sql语句,参数用?占位
 *  @param data 参数数组
 *
 *  @return 字典数组,若无任何结果返回nil
 */
- (nullable NSArray *)executeQuery:(NSString *)sql withParams:(nullable NSArray *)data;

/**
 *  执行批处理SQL语句
 *  需先使用‘open’来打开数据库
 *
 *	@param sql  sql语句
 *  @param flag YES表示执行有返回值,NO表示无返回值
 *
 *  @return 字典数组,若无任何结果返回nil
 */
- (nullable NSArray *)executeStatement:(NSString *)sql flag:(BOOL)isReturn;

/**
 *  执行查询数量的SQL语句
 *  需先使用‘open’来打开数据库
 *
 *	@param sql  sql语句
 *  @return 整形,查询的数量结果
 */
- (long)longForQuery:(NSString *)sql;

/**
 *	返回最近插入操作的Row ID
 */
- (NSUInteger)lastInsertRowId;

@end

NS_ASSUME_NONNULL_END