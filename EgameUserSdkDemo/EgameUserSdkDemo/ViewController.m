//
//  ViewController.m
//  EgameUserSdkDemo
//
//  Created by 刘旦 on 15/10/29.
//  Copyright © 2015年 egame. All rights reserved.
//

#import "ViewController.h"
#import "EgameUserSdk.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)login:(id)sender {
    
    NSLog(@"btn click");
    
    [[EgameUserSdk shareInstance] startWithClientId:@"730988" callback:^(EgameResult result, NSString *ssoCode, int failedReason) {
        // 处理结果
        NSLog(@"The sso code: %@", ssoCode);
        NSLog(@"The result: %d", result);
        NSLog(@"The failed reason: %d", failedReason);
    }];

    
}

@end
