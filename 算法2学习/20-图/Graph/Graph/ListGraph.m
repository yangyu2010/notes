//
//  ListGraph.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import "ListGraph.h"
#import "Vertex.h"
#import "Edge.h"

@interface ListGraph()

@property (nonatomic, strong) NSMutableDictionary *vertexes;
@property (nonatomic, strong) NSMutableSet *edges;

@end

@implementation ListGraph

- (instancetype)init
{
    self = [super init];
    if (self) {
        self.vertexes = [[NSMutableDictionary alloc] init];
        self.edges = [[NSMutableSet alloc] init];
    }
    return self;
}

- (void)debugLog {
    NSLog(@"edgesSize: %ld", [self edgesSize]);
    NSLog(@"vertexesSize: %ld", [self vertexesSize]);
    
    for (id value in self.vertexes.allValues) {
        Vertex *vertex = (Vertex *)value;
        if ([vertex isKindOfClass:[Vertex class]]) {
            NSLog(@"%@", vertex);
            NSLog(@"inEdges: %ld", [vertex.inEdges count]);
            NSLog(@"outEdges: %ld", [vertex.outEdges count]);

            NSLog(@"====inEdges=====");
            for (id inEdge in vertex.inEdges.allObjects) {
                NSLog(@"%@", inEdge);
            }
            NSLog(@"====inEdges=====");

            NSLog(@"====outEdges=====");
            for (id outEdge in vertex.outEdges.allObjects) {
                NSLog(@"%@", outEdge);
            }
            NSLog(@"====outEdges=====");

            NSLog(@"\n");
        }
    }
}

- (NSInteger)edgesSize {
    return [self.edges count];
}

- (NSInteger)vertexesSize {
    return [self.vertexes count];
}

- (void)addVertex:(NSString *)vertex {
    Vertex *v = [[Vertex alloc] init];
    v.value = vertex;
    [self.vertexes setValue:v forKey:vertex];
}

- (void)addEdgeFrom:(NSString *)vertex1 to:(NSString *)vertex2 {
    [self addEdgeFrom:vertex1 to:vertex2 widget:nil];
}

- (void)addEdgeFrom:(NSString *)vertex1 to:(NSString *)vertex2 widget:(nullable NSNumber *)weight {
    Vertex *v1 = [self.vertexes valueForKey:vertex1];
    if (v1 == nil || v1 == NULL) {
        v1 = [[Vertex alloc] init];
        v1.value = vertex1;
        [self.vertexes setValue:v1 forKey:vertex1];
    }
    
    Vertex *v2 = [self.vertexes valueForKey:vertex2];
    if (v2 == nil || v2 == NULL) {
        v2 = [[Vertex alloc] init];
        v2.value = vertex2;
        [self.vertexes setValue:v2 forKey:vertex2];
    }
    
    Edge *edge = [[Edge alloc] init];
    edge.from = v1;
    edge.to = v2;
    edge.weight = weight;
    
    [v1.outEdges removeObject:edge];
    [v2.inEdges removeObject:edge];
    [self.edges removeObject:edge];

    [v1.outEdges addObject:edge];
    [v2.inEdges addObject:edge];
    [self.edges addObject:edge];
}

- (void)removeVertex:(NSString *)vertex {
    for (Vertex *v in self.vertexes.allValues) {
//        if ([v isKindOfClass:[Vertex class]] == NO) {
//            continue;
//        }
        
        for (Edge *edge in v.inEdges.allObjects) {
            if ([edge.to.value isEqualToString:vertex] || [edge.from.value isEqualToString:vertex]) {
                [v.inEdges removeObject:edge];
                [self.edges removeObject:edge];
            }
        }
        
        for (Edge *edge in v.outEdges.allObjects) {
            if ([edge.to.value isEqualToString:vertex] || [edge.from.value isEqualToString:vertex]) {
                [v.outEdges removeObject:edge];
                [self.edges removeObject:edge];
            }
        }
    }
    
    [self.vertexes removeObjectForKey:vertex];
}

- (void)removeEdgeFrom:(NSString *)from to:(NSString *)to {
    for (Vertex *v in self.vertexes.allValues) {
        for (Edge *edge in v.inEdges.allObjects) {
            if ([edge.to.value isEqualToString:to] && [edge.from.value isEqualToString:from]) {
                [v.inEdges removeObject:edge];
                [self.edges removeObject:edge];
            }
        }

        for (Edge *edge in v.outEdges.allObjects) {
            if ([edge.to.value isEqualToString:to] && [edge.from.value isEqualToString:from]) {
                [v.outEdges removeObject:edge];
                [self.edges removeObject:edge];
            }
        }
    }
}


@end
