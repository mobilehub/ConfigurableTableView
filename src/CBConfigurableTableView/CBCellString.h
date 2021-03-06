//
//  CBCellString.h
//  ConfigurableTableView
//
//  Created by Christian Beer on 04.12.09.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CBCell.h"

@interface CBCellString : CBCell {
	UITableViewCellStyle _style;
	
	BOOL _multiline;
	UIFont *_font;
}

@property (nonatomic, assign) UITableViewCellStyle style;
@property (nonatomic, assign) BOOL multiline;
@property (nonatomic, retain) UIFont *font;

+ (id) cellMultilineWithValuePath:(NSString*)path;

- (CBCellString*)applyFont:(UIFont*)font;
- (CBCellString*)applyMultiline;

#pragma mark private

- (CGFloat) calculateHeightForCellInTableView:(UITableView*)tableView withText:(NSString*)text;

@end
