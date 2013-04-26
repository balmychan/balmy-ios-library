//
//  balmy_ios_library.h
//  balmy-ios-library
//
//  Created by 後藤 歩 on 2013/04/26.
//  Copyright (c) 2013年 balmychan. All rights reserved.
//

#import <Foundation/Foundation.h>

// 各種マクロ
#define SAFE_CALLBACK(func, ...) if (func) { func(__VA_ARGS__); }

#define LOG(...)                        NSLog(__VA_ARGS__)
#define DIC_VALUE(dic, key)             [dic objectForKey:key]
#define NSF(key, ...)                   [NSString stringWithFormat:key, __VA_ARGS__]
#define UTF8_TO_DATA(str)               [str dataUsingEncoding:NSUTF8StringEncoding]

#define GET_X(view)                     (view.frame.origin.x)
#define GET_Y(view)                     (view.frame.origin.y)
#define GET_W(view)                     (view.frame.size.width)
#define GET_H(view)                     (view.frame.size.height)

#define GET_R(view)                     (view.frame.origin.x + view.frame.size.width)
#define GET_B(view)                     (view.frame.origin.y + view.frame.size.height)

#define SET_X(view, x)                  view.frame = CGRectMake(x, GET_Y(view), GET_W(view), GET_H(view))
#define SET_Y(view, y)                  view.frame = CGRectMake(GET_X(view), y, GET_W(view), GET_H(view))
#define SET_XY(view, x, y)              view.frame = CGRectMake(x, y, GET_W(view), GET_H(view))
#define SET_W(view, w)                  view.frame = CGRectMake(GET_X(view), GET_Y(view), w, GET_H(view))
#define SET_H(view, h)                  view.frame = CGRectMake(GET_X(view), GET_Y(view), GET_W(view), h)
#define SET_WH(view, w, h)              view.frame = CGRectMake(GET_X(view), GET_Y(view), w, h)
#define SET_XYWH(view, x, y, w, h)      view.frame = CGRectMake(x, y, w, h)

#define GET_B_X(view)                   (view.bounds.origin.x)
#define GET_B_Y(view)                   (view.bounds.origin.y)
#define GET_B_W(view)                   (view.bounds.size.width)
#define GET_B_H(view)                   (view.bounds.size.height)

#define GET_B_R(view)                   (view.bounds.origin.x + view.bounds.size.width)
#define GET_B_B(view)                   (view.bounds.origin.y + view.bounds.size.height)

#define SET_B_X(view, x)                view.bounds = CGRectMake(x, GET_Y(view), GET_W(view), GET_H(view))
#define SET_B_Y(view, y)                view.bounds = CGRectMake(GET_X(view), y, GET_W(view), GET_H(view))
#define SET_B_XY(view, x, y)            view.bounds = CGRectMake(x, y, GET_W(view), GET_H(view))
#define SET_B_W(view, w)                view.bounds = CGRectMake(GET_X(view), GET_Y(view), w, GET_H(view))
#define SET_B_H(view, h)                view.bounds = CGRectMake(GET_X(view), GET_Y(view), GET_W(view), h)
#define SET_B_WH(view, w, h)            view.bounds = CGRectMake(GET_X(view), GET_Y(view), w, h)
#define SET_B_XYWH(view, x, y, w, h)    view.bounds = CGRectMake(x, y, w, h)

#define isNotNilOrEmptyString(string)   (string != nil && 0 < string.length)
#define isNilOrEmptyString(string)      (!isNotNilOrEmptyString(string))

#define RGB(r,g,b)        [UIColor colorWithRed:(r / 255.f) green:(g / 255.f) blue:(b / 255.f) alpha:1.f]
#define RGBA(r,g,b,a)     [UIColor colorWithRed:(r / 255.f) green:(g / 255.f) blue:(b / 255.f) alpha:a]


@interface balmy_ios_library : NSObject

@end
