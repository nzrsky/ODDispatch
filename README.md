
# ODDispatch

[![Build Status](https://app.travis-ci.com/nzrsky/ODDispatch.svg?branch=master)](https://app.travis-ci.com/nzrsky/ODDispatch)
[![codecov.io](https://codecov.io/github/nzrsky/ODDispatch/coverage.svg?branch=master)](https://codecov.io/github/nzrsky/ODDispatch?branch=master)
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/ODDispatch.svg)](https://cocoapods.org/pods/ODDispatch)
[![Carthage compatible](https://img.shields.io/badge/Carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![Platform](https://img.shields.io/cocoapods/p/ODDispatch.svg?style=flat)](http://cocoadocs.org/docsets/ODDispatch)
[![Twitter](https://img.shields.io/badge/twitter-@nzrsky-blue.svg?style=flat)](http://twitter.com/nzrsky)

## Usage

### ODDispatchOnce

```objective-c
@import ODDispatch;

// Before 
static id singletone;
static dispatch_once_t onceToken;
dispatch_once(&onceToken, ^(){
 	singletone = [Singletone new];
});

// After
static id singletone;
ODDispatchOnce(^{
	singletone = [Singletone new];
});

```

### ODDispatchAfter

```objective-c
// Before 
dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
}

// After
ODDispatchAfterInMainThread(2, ^{
});
```

### ODDispatchAsyncInMainThread

```objective-c
// Before 
dispatch_async(dispatch_get_main_queue(), ^{
});

// After
ODDispatchAsyncInMainThread(^{
});
```

### ODDispatchAsyncInBackgroundThread

```objective-c
// Before 
dispatch_async(dispatch_get_global_queue(priority, 0), ^{
});

// After
ODDispatchAsyncInBackgroundThread(^{
});
```

## Installation

ODDispatch is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'ODDispatch'
```

## Author

Alexey Nazarov, alexx.nazaroff@gmail.com

## License

ODDispatch is available under the MIT license. See the LICENSE file for more info.

