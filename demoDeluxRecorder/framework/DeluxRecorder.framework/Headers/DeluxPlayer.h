//
//  DeluxPlayer.h
//  DeluxRecorder
//
//  Created by henry on 2017/8/29.
//  Copyright © 2017年 huang henry. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

typedef enum NSInteger{
    PlayerStatusUnknown,
    PlayerStatusPlay,
    PlayerStatusPause,
    PlayerStatusStop,
    PlayerStatusCache
}DeluxPlayerStatus;

typedef void(^statusCallack)(DeluxPlayerStatus status);

@protocol DeluxPlayerDelegate <NSObject>

- (void)playFinished:(DeluxPlayerStatus)nextCmd;
- (void)playerSyncStatus:(DeluxPlayerStatus)cmd;
- (void)playerClose;

@end

@interface DeluxPlayer : NSObject

@property (nonatomic, strong) UIView *playView;
@property (nonatomic, assign) BOOL loopEnable;
@property (nonatomic, assign) BOOL showProgressIndicator;
@property (nonatomic, copy) statusCallack playerStatusChangeCB;
@property (nonatomic, assign) BOOL pauseEnable;
@property (nonatomic, weak) id<DeluxPlayerDelegate> delegate;
@property (nonatomic, assign) BOOL mute;
@property (nonatomic, strong) AVPlayerItem *curItem;
@property (nonatomic, strong) AVPlayer *player;
@property (nonatomic, assign) DeluxPlayerStatus playerStatus;
@property (nonatomic, strong) UIButton *closeBtn;

/**
 * 是否需要显示关闭按钮
 */
@property (nonatomic, assign) BOOL showCloseBtn;

//初始化
- (id)initWithUrl:(NSURL *)url;

- (id)initWithAsset:(AVAsset *)asset;

- (id)initWithPlayer:(AVPlayer *)player status:(DeluxPlayerStatus)status;

//播放
- (void)playerStart;

- (void)playerRestart;

//暂停
- (void)playerPause;

//停止
- (void)playerStop;

@end
