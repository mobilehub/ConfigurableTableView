//
//  CBTableViewCell.h
//  ConfigurableTableView
//
//  Created by Christian Beer on 04.12.09.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class CBConfigurableTableViewController;
@class CBEditor;
@class CBEditorController;
@class CBSection;

@protocol CBCell <NSObject>

- (NSString*) title;

- (NSString*) reuseIdentifier;
- (UITableViewCell*) createTableViewCellForTableView:(UITableView*)tableView;

/** Use this to update the value in the tableViewCell */
- (void) setValue:(id)value ofCell:(UITableViewCell*)cell inTableView:(UITableView*)tableView;
/** Use this to setup the TableViewCell. Needs only overridden for special cells. 
 * Otherwise override setValue:ofCell: */
- (void) setupCell:(UITableViewCell*)cell withObject:(NSObject*)object inTableView:(UITableView*)tableView;
- (CGFloat) heightForCellInTableView:(UITableView*)tableView withObject:(NSObject*)object;

- (BOOL) hasEditor;
- (void) openEditorInController:(CBConfigurableTableViewController*)controller;
- (void) setEditor:(CBEditor*)editor;

@end


@interface CBCell : NSObject <CBCell> {
	CBConfigurableTableViewController *_controller;
    CBSection *_section;	
    
    NSString *_tag;
	
	NSString *_title;
	NSString *_valueKeyPath;
	
	CBEditor *_editor;
    
    NSString *_iconName;
}

@property (nonatomic, assign) CBConfigurableTableViewController *controller;
@property (nonatomic, assign) CBSection* section;

@property (nonatomic, copy) NSString *tag;

@property (readonly) NSString *title;
@property (readonly) NSString *valueKeyPath;

@property (readonly) NSString *reuseIdentifier;

@property (nonatomic, retain) CBEditor *editor;

@property (nonatomic, retain) NSString *iconName;

- (id) initWithTitle:(NSString*)title;
- (id) initWithTitle:(NSString*)title andValuePath:(NSString*)valueKeyPath;

+ (id) cellWithTitle:(NSString*)title valuePath:(NSString*)valueKeyPath;
+ (id) cellWithTitle:(NSString*)title valuePath:(NSString*)valueKeyPath editor:(CBEditor*)editor;
+ (id) cellWithTitle:(NSString*)title valuePath:(NSString*)valueKeyPath iconName:(NSString*)iconName;

- (id) applyTag:(NSString *)tag;
- (id) applyEditor:(CBEditor *)editor;
- (id) applyIconName:(NSString*)iconName;

@end


/// Utility Methods

CGFloat CBCTVCellLabelWidth(UITableView *tableView);