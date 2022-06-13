//
//  FindUnion.m
//  Graph
//
//  Created by Yu Yang on 6/13/22.
//

#import "FindUnion.h"


@interface FindUnion()

@property (nonatomic, strong) NSMutableDictionary *nodes;
//@property (nonatomic, copy) NSMutableArray<NSNumber *> *parents;
//@property (nonatomic, copy) NSMutableArray *ranks;

@end

@implementation FindUnion

- (instancetype)initWith:(NSInteger)capacity
{
    self = [super init];
    if (self) {
    
        self.nodes = [[NSMutableDictionary alloc] initWithCapacity:capacity];
//        self.parents = [[NSMutableArray alloc] initWithCapacity:capacity];
//        for (NSInteger i = 0; i < capacity; i++) {
//            self.parents[i] = [NSNumber numberWithInteger:i];
//        }
    }
    return self;
}

- (void)set:(NSString *)v {
    Node *node = [[Node alloc] initWith:v];
    [self.nodes setValue:node forKey:v];
//    [self.nodes setValue:node forKey:@"aaaaaa"];
}

- (NSString *)find:(NSString *)v {
    return [self findNode:v].value;
}

- (void)union2:(NSString *)v1 v2:(NSString *)v2 {
    Node *n1 = [self findNode:v1];
    Node *n2 = [self findNode:v2];
    if (n1 == nil || n2 == nil) {
        return;
    }
    if ([n1.value isEqualToString:n2.value]) {
        return;
    }
    
    if (n1.rank < n2.rank) {
        n1.parent = n2;
    } else if (n1.rank > n2.rank) {
        n2.parent = n1;
    } else {
        n1.parent = n2;
        n2.rank += 1;
    }
}

- (BOOL)isSame:(NSString *)v1 v2:(NSString *)v2 {
    Node *n1 = [self findNode:v1];
    Node *n2 = [self findNode:v2];
    return [n1.value isEqualToString:n2.value];
}


- (Node *)findNode:(NSString *)v {
    Node *node = [self.nodes valueForKey:v];
    if (node == nil) {
        return nil;
    }
    while (![node.value isEqualToString:node.parent.value]) {
        node.parent = node.parent.parent;
        node = node.parent;
    }
    return node;
}

@end




@implementation Node
- (instancetype)initWith:(NSString *)value {
    self = [super init];
    if (self) {
        self.value = value;
        self.rank = 1;
        self.parent = self;
    }
    return self;
}
@end

