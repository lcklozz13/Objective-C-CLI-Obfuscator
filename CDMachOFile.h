//
// $Id: CDMachOFile.h,v 1.4 2004/01/06 01:51:53 nygard Exp $
//

//  This file is part of class-dump, a utility for exmaing the
//  Objective-C segment of Mach-O files.
//  Copyright (C) 1997-1998, 2000-2001, 2004  Steve Nygard

#import <Foundation/NSObject.h>

@class NSData;
@class CDSegmentCommand;

#if 0
@interface CDFatMachOFile : NSObject
{
}

@end
#endif

@class NSArray;
@class CDDylibCommand, CDMachOFile;

@protocol CDMachOFileDelegate
- (void)machOFile:(CDMachOFile *)aMachOFile loadDylib:(CDDylibCommand *)aDylibCommand;
@end

@interface CDMachOFile : NSObject
{
    NSString *filename;
    NSData *data;
    const struct mach_header *header;
    NSArray *loadCommands;

    id nonretainedDelegate;
}

- (id)initWithFilename:(NSString *)aFilename;
- (void)dealloc;

- (NSString *)filename;

- (id)delegate;
- (void)setDelegate:(id)newDelegate;

- (void)process;
- (NSArray *)_processLoadCommands;

- (NSArray *)loadCommands;
- (unsigned long)filetype;
- (unsigned long)flags;

- (NSString *)flagDescription;
- (NSString *)description;

- (CDSegmentCommand *)segmentWithName:(NSString *)segmentName;
- (CDSegmentCommand *)segmentContainingAddress:(unsigned long)vmaddr;
- (const void *)pointerFromVMAddr:(unsigned long)vmaddr;
- (const void *)pointerFromVMAddr:(unsigned long)vmaddr segmentName:(NSString *)aSegmentName;
- (NSString *)stringFromVMAddr:(unsigned long)vmaddr;

- (const void *)bytes;

@end