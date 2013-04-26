//
//  BALImageView.h
//  balmy-ios-library
//
//  Created by ayumi.goto on 2013/04/26.
//  Copyright (c) 2013年 balmychan. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BALImageView : UIImageView

//! 非同期でURLから画像を取得してセットする
/**
 * @param url       非同期で読み込みたい画像のURLを指定する
 * @param loaded    読み込み完了後のコールバックを指定する
 */
- (void)setAsyncImageByURL:(NSString*)url
                    loaded:(void (^)())loaded;

@end
