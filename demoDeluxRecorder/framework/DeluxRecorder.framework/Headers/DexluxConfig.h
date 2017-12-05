//
//  DexluxConfig.h
//  DeluxRecorder
//
//  Created by henry on 2017/8/29.
//  Copyright © 2017年 huang henry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface DexluxConfig : NSObject

@property (nonatomic, assign) CGFloat videoWidth;   //视频宽度
@property (nonatomic, assign) CGFloat videoHeight;  //视频高度
@property (nonatomic, assign) CGFloat width;        //上传宽度
@property (nonatomic, assign) CGFloat height;       //上传高度
@property (nonatomic, assign) CGFloat framerate;    //上传帧率
@property (nonatomic, assign) CGFloat bitrate;      //上传码率

- (id)initWithDefaultParameter;

@end
