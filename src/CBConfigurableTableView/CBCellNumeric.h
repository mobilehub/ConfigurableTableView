//
//  CBCellNumeric.h
//  ConfigurableTableView
//
//  Created by Christian Beer on 04.12.09.
//  Copyright 2010 Christian Beer. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CBCell.h"

@interface CBCellNumeric : CBCell {
	NSNumberFormatter *_numberFormatter;
}

@property (nonatomic, retain) NSNumberFormatter *numberFormatter;

@end
