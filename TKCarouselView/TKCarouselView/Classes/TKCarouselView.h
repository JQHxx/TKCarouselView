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

typedef void(^TKItemAtIndexBlock)(UIImageView *imageView,NSInteger index);

@interface TKPageControl : UIPageControl
@property (nonatomic,assign) CGSize currentDotSize;//Current page dot size
@property (nonatomic,assign) CGSize otherDotSize;//Except for the size of the dots on the current page
@property (nonatomic,assign) CGFloat currentDotRadius;//The default is 0
@property (nonatomic,assign) CGFloat otherDotRadius;//The default is 0
@property (nonatomic,assign) CGFloat dotSpacing;//Spacing
@property (nonatomic,assign) DotAlignmentType dotAlignmentType;
@end

@interface TKCarouselView : UIView

//MARK:- CarouselView parameter setting

// Whether to turn on automatic rotoasting (the default is to turn on, it must be imageCount>1, otherwise rotoasting is meaningless)
@property (nonatomic,assign) BOOL isAutoScroll;
//Rotation interval (3 seconds by default)）
@property (nonatomic,assign) NSTimeInterval intervalTime;
// It takes effect when imageCount==0
@property (nonatomic,strong) UIImageView *placeholderImageView;

//MARK:- UIPageControl Related Settings (do not set the default to dots)
@property (nonatomic,strong) TKPageControl *pageControl;

// Whether pagecontrol is hidden or not
@property (nonatomic,assign) BOOL isHiddenPageControl;

@property (nonatomic,assign) BOOL isNeedReloadItemDidScrollOperation;
// scroll current index
@property (nonatomic, copy) void (^itemDidScrollOperationBlock)(NSInteger currentIndex);

/// reload (Must be implemented)
/// @param imageCount imageCount (0-100)
/// @param itemAtIndexBlock A view displayed on the screen
/// @param imageClickedBlock The view is clicked
- (void)reloadImageCount:(NSUInteger)imageCount itemAtIndexBlock:(TKItemAtIndexBlock)itemAtIndexBlock imageClickedBlock:(void(^)(NSInteger index))imageClickedBlock;

- (void)pageControlHidden:(BOOL)isHidden;
- (void)makeScrollViewScrollToIndex:(NSInteger)index;

@end
