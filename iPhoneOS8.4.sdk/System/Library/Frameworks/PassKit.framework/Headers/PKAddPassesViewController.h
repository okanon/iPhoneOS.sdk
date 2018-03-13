//
//  PKAddPassesViewController.h
//  PassKit
//
//  Copyright (c) 2011 Apple, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PKPass;
@class PKAddPassesViewController;

@protocol PKAddPassesViewControllerDelegate <NSObject>
@optional
-(void)addPassesViewControllerDidFinish:(PKAddPassesViewController *)controller; // delegate should dismiss presentation
@end

NS_CLASS_AVAILABLE(NA, 6_0)
@interface PKAddPassesViewController : UIViewController

/* controller should be presented with -presentViewController:animated:completion:
 pass should be a pass you want the user to add.
 */
- (instancetype)initWithPass:(id)pass;
- (instancetype)initWithPasses:(NSArray *)passes NS_AVAILABLE_IOS(7_0);
+ (BOOL)canAddPasses NS_AVAILABLE_IOS(8_0);

@property(nonatomic,assign) id <PKAddPassesViewControllerDelegate> delegate;

@end