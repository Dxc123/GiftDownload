//
//  SDGiftDownload.h
//  SDGiftDownload
//
//  Created by daixingchuang on 2022/1/6.
//

#ifndef SDGiftDownload_h
#define SDGiftDownload_h

#import "SGCacheManager.h"
#import "SGDownloadManager.h"
#import "ReceivedGiftInfo.h"
#import "SGDownloadModel.h"

#import "SDGiftDownloadManager.h"

#endif /* SDGiftDownload_h */


/**
 swift项目 使用：
 导入头文件
 
 #import "SDGiftDownloadHeader.h"
 或者 #import "SDGiftDownload.h"
 
 
  1.下载礼物特效文件
 giftArrs.forEach { (model) in
     let data = ReceivedGiftInfo()
     data.uid = "\(model.gid)"
     data.diamonds = "\(model.diamonds)"
     data.icon = model.icon
     data.name = model.name
     data.animEffectUrl = model.animEffectUrl
     data.updatedAt = "\(model.updatedAt)"
     data.type = "1"
     if SDGiftDownloadManager.isdownloadedGiftFile(data) {
         OLog("本地存在")
     }else{
         OLog("未存在 需要下载")
         SDGiftDownloadManager.downLoadUrl(data)
     }
 }
 
 2.查找本地特效文件
 
  let receive = ReceivedGiftInfo()
  receive.icon = sendGift.icon
  receive.name = sendGift.name
  receive.uid =  "\(sendGift.gid)"
  receive.animEffectUrl = sendGift.animEffectUrl
  receive.updatedAt =  "\(sendGift.updatedAt)"
  receive.type = "1"

 if SDGiftDownloadManager.isdownloadedGiftFile(receive) {
     OLog("本地已下载特效")
    let dict = SDGiftDownloadManager.getThisGiftInfo(receive) as Dictionary
    let filePath = JSON.init(dict["filePath"] as Any ).stringValue
    let fileName = JSON.init(dict["fileName"] as Any ).stringValue
    OLog("filePath = \(filePath)")
    OLog("fileName = \(fileName)")

     if sendGift.animEffectUrl.hasSuffix("mp4") {
        //播放特效
     }
 }else{
     OLog("本地未下载特效")
 }
 
 
 
 
 */
