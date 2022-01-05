//
//  ReceivedGiftInfo.h
//  Bibu
//
//  Created by daixingchuang on 2020/10/17.
//  Copyright © 2020 DiscoverJoy. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ReceivedGiftInfo : NSObject
@property (nullable, nonatomic, copy) NSString  *diamonds;//礼物价格
@property (nullable, nonatomic, copy) NSString  *icon;//礼物icon地址
@property (nullable, nonatomic, copy) NSString  *name;//礼物名字
@property (nullable, nonatomic, copy) NSString  *uid;//礼物id
@property (nullable, nonatomic, copy) NSString  *quantity;//数量
@property (nullable, nonatomic, copy) NSString  *message;//
@property (nullable, nonatomic, copy) NSString  *animEffectUrl;//特效动画文件地址
@property (nullable, nonatomic, copy) NSString  *updatedAt;//礼物更新时间



///礼物类型
//1 旧lottie动画礼物  2，3，4分别代表小，半屏，全屏  SVGA动画礼物
// 1、2 lottie播放
//3、 4 SVGAPlayer播放
@property (nullable, nonatomic, copy) NSString  *type;

///礼物编号id
//@property (nullable, nonatomic, copy) NSString  *gid;


@end

NS_ASSUME_NONNULL_END
