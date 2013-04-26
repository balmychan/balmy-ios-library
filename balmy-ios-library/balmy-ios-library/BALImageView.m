//
//  BALImageView.m
//  balmy-ios-library
//
//  Created by ayumi.goto on 2013/04/26.
//  Copyright (c) 2013年 balmychan. All rights reserved.
//

#import "BALImageView.h"

@interface BALImageView ()

// private properties
@property (nonatomic, retain) NSOperationQueue* queue;

@end

@implementation BALImageView {
    NSOperationQueue* _queue;
}

@synthesize
    queue = _queue;

//! 破棄処理
- (void)dealloc
{
    self.queue = nil;
}

#pragma mark AsyncLoad

//! 非同期で画像をセットする
/**
 * @param url       非同期で読み込みたい画像のURLを指定する
 * @param loaded    読み込み完了後のコールバックを指定する
 */
- (void)setAsyncImageByURL:(NSString*)url
                    loaded:(void (^)())loaded
{  
    NSURLRequest* request = [[NSURLRequest alloc] initWithURL:[NSURL URLWithString:url]
                                                  cachePolicy:NSURLRequestReturnCacheDataElseLoad
                                              timeoutInterval:60];
    self.queue = [NSOperationQueue new];
    __weak BALImageView* me = self;
    [NSURLConnection sendAsynchronousRequest:request
                                       queue:self.queue
                           completionHandler:^(NSURLResponse* response, NSData* data, NSError* error)
     {
         __block NSURLResponse* blockResponse = response;
         __block NSData* blockData            = data;
         __block NSError* blockError          = error;
         dispatch_async(dispatch_get_main_queue(), ^{
             [me completeAsyncImage:blockResponse data:blockData error:blockError loaded:loaded];
             blockResponse = nil, blockData = nil, blockError = nil;
         });
     }];
}

//! 非同期ロードの完了後に呼ばれる
- (void)completeAsyncImage:(NSURLResponse*)response data:(NSData*)data error:(NSError*)error loaded:(void (^)())loaded
{
    UIImage* image = [UIImage imageWithData:data];
    self.image = image;
    SAFE_CALLBACK(loaded);
}

#pragma mark properties

//! queueプロパティのsetter
- (void)setQueue:(NSOperationQueue *)queue
{
    if (_queue != nil) {
        [_queue cancelAllOperations];
        _queue = queue;
    }
}

@end
