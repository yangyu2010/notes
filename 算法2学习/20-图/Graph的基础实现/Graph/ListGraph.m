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
    NSLog(@"\n");
    
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

- (void)addEdgeFrom:(NSString *)from to:(NSString *)to {
    [self addEdgeFrom:from to:to widget:nil];
}

- (void)addEdgeFrom:(NSString *)from to:(NSString *)to widget:(nullable NSNumber *)weight {
    Vertex *fromVertex = [self.vertexes valueForKey:from];
    if (fromVertex == nil || fromVertex == NULL) {
        fromVertex = [[Vertex alloc] init];
        fromVertex.value = from;
        [self.vertexes setValue:fromVertex forKey:from];
    }
    
    Vertex *toVertex = [self.vertexes valueForKey:to];
    if (toVertex == nil || toVertex == NULL) {
        toVertex = [[Vertex alloc] init];
        toVertex.value = to;
        [self.vertexes setValue:toVertex forKey:to];
    }
    
    Edge *edge = [[Edge alloc] init];
    edge.from = fromVertex;
    edge.to = toVertex;
    edge.weight = weight;
    
    [fromVertex.outEdges removeObject:edge];
    [toVertex.inEdges removeObject:edge];
    [self.edges removeObject:edge];

    [fromVertex.outEdges addObject:edge];
    [toVertex.inEdges addObject:edge];
    [self.edges addObject:edge];
}

- (void)removeVertex:(NSString *)vertex {
    Vertex *v = [self.vertexes valueForKey:vertex];
    if (v == nil || v == NULL) {
        return;
    }
    
    for (Edge *e in v.outEdges.allObjects) {
        [e.to.inEdges removeObject:e];
        [self.edges removeObject:e];
    }
    
    for (Edge *e in v.inEdges.allObjects) {
        [e.from.outEdges removeObject:e];
        [self.edges removeObject:e];
    }

    [self.vertexes removeObjectForKey:vertex];
}

- (void)removeEdgeFrom:(NSString *)from to:(NSString *)to {
    Vertex *fromVertex = [self.vertexes valueForKey:from];
    if (fromVertex == nil || fromVertex == NULL) {
        return;
    }
    
    Vertex *toVertex = [self.vertexes valueForKey:to];
    if (toVertex == nil || toVertex == NULL) {
        return;
    }
    
    Edge *edge = [[Edge alloc] init];
    edge.from = fromVertex;
    edge.to = toVertex;
    
    [fromVertex.outEdges removeObject:edge];
    [toVertex.inEdges removeObject:edge];
    [self.edges removeObject:edge];
}

- (void)bfs:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }
    
    /// 在iOS中没有队列这种数据结构 我这里用的是普通数组
    /// 每次移除第一个 在末尾添加新的
    NSMutableSet<Vertex *> *visitedVertex = [[NSMutableSet alloc] init];
    NSMutableArray<Vertex *> *array = [[NSMutableArray alloc] init];
    [array addObject:beginVertex];
    [visitedVertex addObject:beginVertex];
    
    while (array.count > 0) {
        Vertex *vertex = array.firstObject;
        NSLog(@"%@", vertex);
        [array removeObjectAtIndex:0];
        
        for (Edge *e in vertex.outEdges) {
            if ([visitedVertex containsObject:e.to]) {
                continue;
            }
            [array addObject:e.to];
            [visitedVertex addObject:e.to];
        }
    }
    
}

/*
 dfs递归版本
- (void)dfs:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }

    NSMutableSet<Vertex *> *visitedVertex = [[NSMutableSet alloc] init];
    [visitedVertex addObject:beginVertex];

    [self dfsVertex:beginVertex visitedVertex:visitedVertex];
}

- (void)dfsVertex:(Vertex *)vertex visitedVertex:(NSMutableSet<Vertex *> *)visitedVertex {
    NSLog(@"%@", vertex);
    
    for (Edge *e in vertex.outEdges) {
        if ([visitedVertex containsObject:e.to]) {
            continue;
        }
        [visitedVertex addObject:e.to];
        [self dfsVertex:e.to visitedVertex:visitedVertex];
    }
}
*/

- (void)dfs:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }

    /// 在iOS中没有栈这种数据结构 我这里用的是普通数组
    /// 先进后出
    NSMutableSet<Vertex *> *visitedVertex = [[NSMutableSet alloc] init];
    NSMutableArray<Vertex *> *array = [[NSMutableArray alloc] init];
    [array addObject:beginVertex];
    [visitedVertex addObject:beginVertex];
    NSLog(@"%@", beginVertex);

    while (array.count > 0) {
        Vertex *vertex = array.lastObject;
        [array removeLastObject];

        for (Edge *e in vertex.outEdges) {
            if ([visitedVertex containsObject:e.to]) {
                continue;
            }
            [array addObject:e.from];
            [array addObject:e.to];
            [visitedVertex addObject:e.to];
            NSLog(@"%@", e.to);
            break;
        }
    }
}

@end
