# demoDeluxRecorder
提供快捷的短视频录制接口，两行代码即可轻松搞定。如果需要自定义操作，请联系客服400-6122-968

```objective-c
self.recorder = [[DeluxRecorderVC alloc] initWithRecorderConfig:nil];
self.recorder.minRecorderDuraion = 3.0;
    
UINavigationController *navi = [[UINavigationController alloc] initWithRootViewController:recorder];
[self presentViewController:navi animated:YES completion:nil];

