//
//  SDGiftDownloadManager.m
//  Bibu
//
//  Created by daixingchuang on 2020/10/19.
//  Copyright © 2020 DiscoverJoy. All rights reserved.
//

#import "SDGiftDownloadManager.h"
//精准打印log
#ifdef DEBUG
#define AALog(s, ... ) printf("[ %s:(%d) ] %s :%s\n", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(s), ##__VA_ARGS__] UTF8String])
#else
#define AALog(s, ... )
#endif

@implementation SDGiftDownloadManager
/**
 下载礼物特效
 */
+ (void)downLoadUrl:(ReceivedGiftInfo *)model {
    
    SGDownloadManager *manager = [SGDownloadManager shareManager];
    [manager downloadWithURL:model
            progress:^(NSInteger completeSize, NSInteger expectSize) { //下载进度
//                    NSLog(@"任务：-- %.2f%%",100.0 * completeSize / expectSize);
                }
            complete:^(NSDictionary *respose, NSError *error) { // 下载完成回调
                    if(error) { // 失败回调
                        AALog(@"任务：下载错误%@",error);
                        return;
                    }
        AALog(@"任务：下载完成 respose = %@",respose);

        }];
}
/**
 本地是否存在这个礼物
 */
+ (BOOL)isdownloadedGiftFile:(ReceivedGiftInfo *)model{
    BOOL isExt = NO;
    // 本地查找
        NSDictionary *fileInfo = [SGCacheManager queryFileInfoWithUrl:[NSURL URLWithString:model.animEffectUrl].absoluteString];
//     本地存在直接返回
        if ([fileInfo[isFinished] integerValue] && [[SGCacheManager updatedAtTimeWith:[NSURL URLWithString:model.animEffectUrl].absoluteString] isEqualToString:model.updatedAt]) {
            AALog(@"本地已经存在");
            isExt = YES;
           
        }else{
            isExt = NO;
        }
    return isExt;
}

/**
 get这个礼物信息
 */
+ (NSDictionary *)getThisGiftInfo:(ReceivedGiftInfo *)model{
    NSDictionary *fileInfo = [SGCacheManager queryFileInfoWithUrl:[NSURL URLWithString:model.animEffectUrl].absoluteString];
    return fileInfo;
}

/**
 APP启动后下载缓存所有礼物特效
 
 */
+ (void)downLoadAllGift:(NSMutableArray *)gifts{
    
    if (gifts.count==0) {
        return;
    }
    for (int i = 0; i<gifts.count; i++) {
        ReceivedGiftInfo *model = gifts[i];
        SGDownloadManager *manager = [SGDownloadManager shareManager];
        [manager downloadWithURL:model
                progress:^(NSInteger completeSize, NSInteger expectSize) { //下载进度
    //                    NSLog(@"任务：-- %.2f%%",100.0 * completeSize / expectSize);
                    }
                complete:^(NSDictionary *respose, NSError *error) { // 下载完成回调
                        if(error) { // 失败回调
                            NSLog(@"任务：下载错误%@",error);
                            return;
                        }
            AALog(@"任务：下载完成 respose = %@ i = %d",respose,i);
          
                }];
    }
    
  
}
@end
