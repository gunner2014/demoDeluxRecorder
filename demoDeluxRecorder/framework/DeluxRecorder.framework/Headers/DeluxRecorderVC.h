//
//  DeluxRecorderVC.h
//  DeluxRecorder
//
//  Created by henry on 2017/8/25.
//  Copyright © 2017年 huang henry. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "DexluxConfig.h"

//注册消息
#define NotificationAfterVideoFileSaved @"NotificationAfterVideoFileSaved"
#define kVideoUrl   @"kVideoUrl"
#define kImage      @"kImage"

@interface DeluxRecorderVC : UIViewController

@property (nonatomic, assign) CGFloat minRecorderDuraion;

//配置录像参数，nil表示使用默认值
- (id)initWithRecorderConfig:(DexluxConfig *)config;

- (id)initWithRecorderConfig:(DexluxConfig *)config waterMark:(UIImage *)img;

- (void)recorderRelease;

@end
