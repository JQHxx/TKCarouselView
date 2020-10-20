//
//  ZJJCarouselView.h
//  ZJJCarouselViewExample
//
//  Created by libtinker on 2018/5/3.
//  Copyright © 2018年 libtinker. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, DotAlignmentType) {
    DotAlignmentTypeLeft = 0,
    DotAlignmentTypeCenter = 1,
    DotAlignmentTypeRight = 2,
};

typedef void(^TKItemAtIndexBlock)(UIImageView * _Nullable imageView,NSInteger index);


@protocol TKPageControlDelegate <NSObject>

- (void)pageControlTapIndex:(NSInteger)index;

@end

@interface TKPageControl : UIView

@property (nonatomic, weak) id<TKPageControlDelegate> _Nullable delegate;

/// default is 0
@property (nonatomic, assign) NSInteger numberOfPages;

/// default is 0. Value is pinned to 0..numberOfPages-1
@property (nonatomic, assign) NSInteger currentPage;

/// The tint color for non-selected indicators. Default is nil.
@property (nullable, nonatomic, strong) UIColor *pageIndicatorTintColor ;

/// The tint color for the currently-selected indicators. Default is nil.
@property (nullable, nonatomic, strong) UIColor *currentPageIndicatorTintColor;

//Current page dot size
@property (nonatomic,assign) CGSize currentDotSize;
//Except for the size of the dots on the current page
@property (nonatomic,assign) CGSize otherDotSize;
//The default is 0
@property (nonatomic,assign) CGFloat currentDotRadius;
//The default is 0
@property (nonatomic,assign) CGFloat otherDotRadius;
//Spacing
@property (nonatomic,assign) CGFloat dotSpacing;
@property (nonatomic,assign) DotAlignmentType dotAlignmentType;;


@end

@class TKCarouselView;
@protocol TKCarouselViewDelegate <NSObject>

/** 点击图片回调 */
- (void)cycleScrollView:(TKCarouselView *_Nullable)cycleScrollView didSelectItemAtIndex:(NSInteger)index;

/** 图片滚动回调 */
- (void)cycleScrollView:(TKCarouselView *_Nullable)cycleScrollView didScrollToIndex:(NSInteger)index;

@end

@interface TKCarouselView : UIView

@property (nonatomic, weak) id<TKCarouselViewDelegate> _Nullable delegate;

//MARK:- CarouselView parameter setting

// Whether to turn on automatic rotoasting (the default is to turn on, it must be imageCount>1, otherwise rotoasting is meaningless)
@property (nonatomic,assign) BOOL autoScroll;

//Rotation interval (3 seconds by default)）
@property (nonatomic,assign) NSTimeInterval autoScrollTimeInterval;

// It takes effect when imageCount==0
@property (nonatomic,strong) UIImageView * _Nullable placeholderImageView;

//MARK:- UIPageControl Related Settings (do not set the default to dots)
@property (nonatomic,strong) TKPageControl * _Nullable pageControl;

@property (nonatomic,assign) BOOL isNeedReloadFirstDidScrollCallBack;

// scroll current index
@property (nonatomic, copy) void (^ _Nullable itemDidScrollOperationBlock)(NSInteger currentIndex);

/// reload (Must be implemented)
/// @param imageCount imageCount (0-100)
/// @param itemAtIndexBlock A view displayed on the screen
/// @param imageClickedBlock The view is clicked
- (void)reloadImageCount:(NSUInteger)imageCount itemAtIndexBlock:(TKItemAtIndexBlock _Nullable )itemAtIndexBlock imageClickedBlock:(void(^_Nullable)(NSInteger index))imageClickedBlock;

- (void)pageControlHidden:(BOOL)isHidden;
- (void)makeScrollViewScrollToIndex:(NSInteger)index;

@end
