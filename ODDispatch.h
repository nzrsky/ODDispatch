// ODDispatch.h
//
// Copyright (c) 2009-2015 Alexey Nazaroff, AJR
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#if __BLOCKS__

/*!
 * @function ODDispatchAsyncInMainThread
 *
 * @abstract
 * Submits a block for asynchronous execution on a main queue.
 *
 * @param block
 * The block to submit to the target dispatch queue. This function performs
 * Block_copy() and Block_release() on behalf of callers.
 * The result of passing NULL in this parameter is undefined.
 */
NS_INLINE
void ODDispatchAsyncInMainThread(dispatch_block_t block) {
    dispatch_async(dispatch_get_main_queue(), block);
}

/*!
 * @function ODDispatchAsyncInBackgroundThread
 *
 * @abstract
 * Submits a block for asynchronous execution on a background queue.
 *
 * @param priority
 * Priorities:
 *  - DISPATCH_QUEUE_PRIORITY_HIGH
 *  - DISPATCH_QUEUE_PRIORITY_DEFAULT
 *  - DISPATCH_QUEUE_PRIORITY_LOW
 *  - DISPATCH_QUEUE_PRIORITY_BACKGROUND
 *
 * @param block
 * The block to submit to the target dispatch queue. This function performs
 * Block_copy() and Block_release() on behalf of callers.
 * The result of passing NULL in this parameter is undefined.
 */
NS_INLINE
void ODDispatchAsyncInBackgroundThread(dispatch_queue_priority_t priority, dispatch_block_t block) {
    dispatch_async(dispatch_get_global_queue(priority, 0), block);
}

/*!
 * @function ODDispatchAfterInMainThread
 *
 * @abstract
 * Submits a block for execution on a main queue with delay.
 *
 * @param delay 
 * Delay in seconds
 *
 * @param block
 * The block to submit to the target dispatch queue. This function performs
 * Block_copy() and Block_release() on behalf of callers.
 * The result of passing NULL in this parameter is undefined.
 */
NS_INLINE
void ODDispatchAfterInMainThread(float delay, dispatch_block_t block) {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t) (delay * NSEC_PER_SEC)), dispatch_get_main_queue(), block);
}


#import "ODStringify.h"

/*!
 * @function ODDispatchOnce
 *
 * @abstract
 * Execute a block once and only once.
 *
 * @param block
 * The block to execute.
 */
#define ODDispatchOnce(block)                                                   \
    static dispatch_once_t ODConcat(od_onceToken, __LINE__);                    \
    dispatch_once(&ODConcat(od_onceToken, __LINE__), (block));
#endif
