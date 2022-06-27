//
//  FindUnion.h
//  Graph
//
//  Created by Yu Yang on 6/13/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FindUnion : NSObject

- (instancetype)initWithCapacity:(NSInteger)capacity;

- (void)set:(NSString *)v;
- (NSString *)find:(NSString *)v;
- (void)union2:(NSString *)v1 v2:(NSString *)v2;
- (BOOL)isSame:(NSString *)v1 v2:(NSString *)v2;

@end

@interface Node : NSObject
@property (nonatomic, copy) NSString *value;
@property (nonatomic, strong) Node *parent;
@property (nonatomic, assign) NSInteger rank;
- (instancetype)initWith:(NSString *)value;
@end

NS_ASSUME_NONNULL_END
