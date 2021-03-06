//
//  CBCellOptions.m
//  ConfigurableTableView
//
//  Created by Christian Beer on 28.01.10.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import "CBConfigurableTableView/CBCellOptions.h"

#import "CBConfigurableTableView/CBPickerOption.h"

@implementation CBCellOptions

- (id) initWithTitle:(NSString*)title andValuePath:(NSString*)valuePath andPickerOptions:(NSArray*)options {
	if (self = [super initWithTitle:title andValuePath:valuePath]) {
		_style = UITableViewCellStyleValue1;
		_multiline = NO;
		
		
		NSMutableDictionary *d = [[NSMutableDictionary alloc] init];
		for (CBPickerOption *o in options) {
			[d setObject:o.label forKey:o.value];
		}
		_options = d;
	}
	return self;
}

+ (CBCellOptions*) cellWithTitle:(NSString*)title valuePath:(NSString*)valuePath pickerOptions:(NSArray*)options {
	CBCellOptions *cell = [[[self class] alloc] initWithTitle:title 
                                                 andValuePath:valuePath
                                             andPickerOptions:options];
	return [cell autorelease];
}

+ (CBCellOptions*) cellWithTitle:(NSString*)title valuePath:(NSString*)valuePath pickerOptions:(NSArray*)options editor:(CBEditor*)editor {
	CBCellOptions *cell = [[[self class] alloc] initWithTitle:title 
                                                 andValuePath:valuePath
                                             andPickerOptions:options];
	cell.editor = editor;
	return [cell autorelease];
}

- (CBCellOptions*) applyDefaultValue:(NSObject*) defaultValue;
{
    _defaultValue = defaultValue;
    
    return self;
}

- (void) dealloc
{
	[_options release], _options = nil;
    [_defaultValue release], _defaultValue = nil;
	
	[super dealloc];
}


#pragma mark CBCell protocol

- (NSString*) reuseIdentifier {
	return @"CBCellOptions";
}

- (void) setValue:(id)value 
		   ofCell:(UITableViewCell*)cell
	  inTableView:(UITableView*)tableView {
	value = [_options objectForKey:value];
    if (!value && _defaultValue) {
        value = [_options objectForKey:_defaultValue];
    }
	
	[super setValue:value ofCell:cell inTableView:tableView];
}

@end
