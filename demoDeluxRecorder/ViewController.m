//
//  ViewController.m
//  demoDeluxRecorder
//
//  Created by henry on 2017/12/4.
//  Copyright © 2017年 huang henry. All rights reserved.
//

#import "ViewController.h"
#import <DeluxRecorder/DeluxRecorder.h>

@interface ViewController ()
{
    DeluxRecorderVC *recorder;
    DeluxPlayer *player;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(notificationFileSaved:) name:NotificationAfterVideoFileSaved object:nil];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)action_record:(id)sender {
    
    if (recorder) {
        [recorder recorderRelease];
    }
    
    /**
     * 默认会有www.deluxapp.com水印
     */
    recorder = [[DeluxRecorderVC alloc] initWithRecorderConfig:nil];
    recorder.minRecorderDuraion = 3.0;
    
    
    UINavigationController *navi = [[UINavigationController alloc] initWithRootViewController:recorder];
    [self presentViewController:navi animated:YES completion:nil];
}

- (IBAction)action_play:(id)sender {
    if (self.label.text.length == 0) {
        return ;
    }
    NSURL *url2 = [NSURL fileURLWithPath:self.label.text];
    

    player = [[DeluxPlayer alloc] initWithUrl:url2];
    //    player.showCloseBtn = YES;
    player.playerStatusChangeCB = ^(DeluxPlayerStatus status){
        if (status == PlayerStatusStop) {
            NSLog(@"play finished");
            player = nil;
        }
    };
    player.playView.frame = self.imgView.frame;
    //    player.loopEnable = YES;
    [self.view addSubview:player.playView];
    [player playerStart];
}

- (void)notificationFileSaved:(NSNotification *)noti{
    NSDictionary *dic = noti.userInfo;
    dispatch_async(dispatch_get_main_queue(), ^{
        self.imgView.image = dic[kImage];
        self.label.text = dic[kVideoUrl];
    });
    
}
@end
