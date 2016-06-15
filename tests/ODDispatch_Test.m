//
//  ODDispatch_Test.m
//  ODXCore
//
//  Created by Alex Nazaroff on 15.06.16.
//  Copyright © 2016 AJR. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "ODXCore.h"

@interface ODDispatch_Test : XCTestCase
@end

@implementation ODDispatch_Test

- (void)testDispatchAsyncInBackgroundThread {
    ODDispatchAsyncInBackgroundThread(DISPATCH_QUEUE_PRIORITY_DEFAULT, ^{
        XCTAssert(![NSThread isMainThread]);
    });
}

- (void)testAsyncInMainThread {
    ODDispatchAsyncInMainThread(^{
        XCTAssert([NSThread isMainThread]);
    });
}

- (void)testDispatchAfterInMainThread {
    static const double t = 0.1;
    NSTimeInterval timeBefore = [NSDate timeIntervalSinceReferenceDate];
    ODDispatchAfterInMainThread(t, ^{
        NSTimeInterval timeAfter = [NSDate timeIntervalSinceReferenceDate];
        XCTAssert([NSThread isMainThread]);
        XCTAssert((timeAfter - timeBefore) >= t);
    });
}

- (void)testDispatchOnce {
    static int x = 0;
    for (int i=0; i < 3; ++i) {
        ODDispatchOnce(^{
            x++;
        });
    }
    
    XCTAssert(x == 1);
}

@end