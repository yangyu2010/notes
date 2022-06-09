//
//  Vertex.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import "Vertex.h"

@implementation Vertex

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.inEdges = [[NSMutableSet alloc] init];
        self.outEdges = [[NSMutableSet alloc] init];
    }
    return self;
}

- (BOOL)isEqual:(id)object {
    Vertex *v = (Vertex *)object;
    if ([v isKindOfClass:[Vertex class]] == NO) {
        return NO;
    }
    
    return [v.value isEqualToString:self.value];
}

- (NSUInteger)hash {
    return self.value.hash;
}

- (NSString *)description {
    return [NSString stringWithFormat:@"%@", self.value];
}


@end
