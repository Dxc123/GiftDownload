//
//  SDGiftDownloadManager.h
//  Bibu
//
//  Created by daixingchuang on 2020/10/19.
//  Copyright © 2020 DiscoverJoy. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SGDownloadManager.h"
#import "SGCacheManager.h"
#import "ReceivedGiftInfo.h"
NS_ASSUME_NONNULL_BEGIN

@interface SDGiftDownloadManager : NSObject

/**
 下载礼物特效
 
 */
+ (void)downLoadUrl:(ReceivedGiftInfo *)model;

/**
 本地是否存在这个礼物
 */
+ (BOOL)isdownloadedGiftFile:(ReceivedGiftInfo *)model;


/**
 get本地已下载的礼物信息
 */
+ (NSDictionary *)getThisGiftInfo:(ReceivedGiftInfo *)model;

/**
下载缓存所有礼物特效
 
 */
+ (void)downLoadAllGift:(NSMutableArray *)gifts;
@end

NS_ASSUME_NONNULL_END
