//
//  Edge.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import "Edge.h"

@implementation Edge


- (BOOL)isEqual:(id)object {
    Edge *e = (Edge *)object;
    if ([e isKindOfClass:[Edge class]] == NO) {
        return NO;
    }
    
    return [e.from isEqual:self.from] && [e.to isEqual:self.to];
}

/**
 一定要重新Edge的hash方法 不然在Set中删除时会有bug
 */
- (NSUInteger)hash {
    return self.from.hash * 31 + self.to.hash;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"%@->%@(%@)", self.from, self.to, self.weight];
}

@end
