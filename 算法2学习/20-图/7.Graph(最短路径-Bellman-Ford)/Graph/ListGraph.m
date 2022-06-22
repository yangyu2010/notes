//
//  ListGraph.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import "ListGraph.h"
#import "Vertex.h"
#import "Edge.h"
#import "FindUnion.h"

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

- (NSArray<NSString *> *)topologicalSort {
    NSMutableArray<NSString *> *array = [[NSMutableArray alloc] init];
    NSMutableArray<Vertex *> *queue = [[NSMutableArray alloc] init];
    NSMutableDictionary *inDegree = [[NSMutableDictionary alloc] init];
    
    for (Vertex *v in self.vertexes.allValues) {
        NSInteger count = [v.inEdges count];
        if (count == 0) {
            [queue addObject:v];
        } else {
            [inDegree setValue:[NSNumber numberWithInteger:count] forKey:v.value];
        }
    }
    
    while (queue.count > 0) {
        Vertex *v = queue.firstObject;
        [queue removeObjectAtIndex:0];
        [array addObject:v.value];
        
        for (Edge *e in v.outEdges) {
            NSInteger count = [[inDegree valueForKey:e.to.value] integerValue] - 1;
            if (count== 0) {
                [queue addObject:e.to];
            }
            [inDegree setValue:[NSNumber numberWithInteger:count] forKey:e.to.value];
        }
    }
    
    return array.copy;
}

//- (void)prim {
//
//    Vertex *beginVertex = self.vertexes.allValues.firstObject;
//    if (beginVertex == nil) {
//        return;
//    }
//    NSMutableSet<Vertex *> *vertexSet = [[NSMutableSet alloc] init];
//    NSMutableSet<Edge *> *edgeSet = [[NSMutableSet alloc] init];
//    [vertexSet addObject:beginVertex];
//
//    while (vertexSet.count != self.vertexes.count) {
//        Vertex *searchV = nil;
//        Edge *searchE = nil;
//        for (Edge *e in self.edges) {
//            if ([edgeSet containsObject:e]) {
//                continue;
//            }
//            if ([vertexSet containsObject:e.from] && [vertexSet containsObject:e.to] == NO) {
//                if (searchE == nil || [e.weight integerValue] < [searchE.weight integerValue]) {
//                    searchE = e;
//                    searchV = e.to;
//                }
//            }
//
//            if ([vertexSet containsObject:e.to] && [vertexSet containsObject:e.from] == NO) {
//                if (searchE == nil || [e.weight integerValue] < [searchE.weight integerValue]) {
//                    searchE = e;
//                    searchV = e.from;
//                }
//            }
//        }
//
//        if (searchV != nil) {
//            [vertexSet addObject:searchV];
//        }
//
//        if (searchE != nil) {
//            [edgeSet addObject:searchE];
//        }
//    }
//
//    NSLog(@"%@", vertexSet);
//    NSLog(@"%@", edgeSet);
//
//}


- (void)prim {

    Vertex *beginVertex = self.vertexes.allValues.firstObject;
    if (beginVertex == nil) {
        return;
    }
    
    // 已经遍历的节点集合
    NSMutableSet<Vertex *> *vertexSet = [[NSMutableSet alloc] init];
    [vertexSet addObject:beginVertex];

    // 已经切分完成的边 横切边
    NSMutableSet<Edge *> *edgeSet = [[NSMutableSet alloc] init];
    
    // 需要切分的边
    // 这些边都是在Vertex的outEdges中
    NSMutableSet<Edge *> *edgeSetFor = [[NSMutableSet alloc] init];

    // 找最小值 应该用堆
    // Objective-C 里没有小顶堆
    while (vertexSet.count != self.vertexes.count) {
        Vertex *searchV = nil;
        Edge *searchE = nil;
        
        for (Vertex *v in vertexSet) {
            [edgeSetFor addObjectsFromArray:v.outEdges.allObjects];
        }
        
        for (Edge *edge in edgeSetFor) {
            // 如果这条边已经存在了
            if ([edgeSet containsObject:edge]) {
                continue;
            }
            // 如果这条边连接的是已经遍历的顶点
            if ([vertexSet containsObject:edge.to]) {
                continue;
            }
            if (searchE == nil || [edge.weight integerValue] < [searchE.weight integerValue]) {
                searchE = edge;
                searchV = edge.to;
            }
        }
        
        if (searchV != nil) {
            [vertexSet addObject:searchV];
        }

        if (searchE != nil) {
            [edgeSet addObject:searchE];
        }
    }
    
    NSLog(@"%@", vertexSet);
    NSLog(@"%@", edgeSet);

}

- (void)kruskal {
    // 按照边的权重顺序（从小到大）将边加入生成树中，直到生成树中含有V-1条边为止（V是顶点数量）
    // 若加入该边会与生成树形成环，则不加入该边
    // 从第3条边开始，可能会与生成树形成环

    // 找最小值 应该用堆
    // Objective-C 里没有小顶堆
    NSMutableSet<Vertex *> *vertexSet = [[NSMutableSet alloc] init];
    NSMutableSet<Edge *> *edgeSet = [[NSMutableSet alloc] init];
    NSMutableSet<Edge *> *edgeSetFor = [[NSMutableSet alloc] initWithSet:self.edges];

    // 初始化并查集
    FindUnion *fu = [[FindUnion alloc] initWithCapacity:20];
    for (Vertex *v in self.vertexes.allValues) {
        [fu set:v.value];
    }
    
    while (edgeSet.count < self.vertexes.count - 1) {
        Vertex *searchV = nil;
        Edge *searchE = nil;
        
        for (Edge *e in edgeSetFor) {
            if ([edgeSet containsObject:e]) {
                continue;
            }
            
            // 找出当前最小的一个
            if (searchE == nil || [e.weight integerValue] < [searchE.weight integerValue]) {
                searchE = e;
                searchV = e.from;
            }
        }
        
        if (searchV != nil && searchE != nil) {
            if ([fu isSame:searchE.to.value v2:searchE.from.value]) {
                [edgeSetFor removeObject:searchE];
                continue;
            }
            [fu union2:searchE.to.value v2:searchE.from.value];
            
            [vertexSet addObject:searchV];
            [edgeSet addObject:searchE];
            [edgeSetFor removeObject:searchE];
        }
    }
    
    NSLog(@"%@", vertexSet);
    NSLog(@"%@", edgeSet);

}


// 最短路径
- (void)dijkstra:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }
    
    NSMutableDictionary *pathDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *selectedEdgesDict = [[NSMutableDictionary alloc] init];

    // 第一步 把起点的所有outEdges加入
    // 更新到路径表中
    for (Edge *e in beginVertex.outEdges) {
        [pathDict setValue:e.weight forKey:e.to.value];
        [selectedEdgesDict setValue:@[e] forKey:e.to.value];
    }
    
    // 第二步 从路径表中 找到最小权重的边
    while (pathDict.count > 0) {
        Vertex *minV = nil;
        NSNumber *minWeight = nil;
        for (NSString *key in pathDict.allKeys) {
            NSNumber *weight = [pathDict valueForKey:key];
            if (minWeight == nil || [weight integerValue] < [minWeight integerValue]) {
                minWeight = weight;
                minV = [self.vertexes valueForKey:key];
            }
        } 

        if (minV != nil) {
            [pathDict removeObjectForKey:minV.value];
            [selectedPathDict setValue:minWeight forKey:minV.value];
            
            // 第三步 遍历当前顶点的outEdges 进行松弛操作
            for (Edge *e in minV.outEdges) {
//                if ([selectedPathDict.allKeys containsObject:e.to.value] || [e.to.value isEqualToString:beginVertex.value]) {
//                    continue;
//                }
                
                if ([selectedPathDict.allKeys containsObject:e.to.value]) {
                    continue;
                }
                
//                NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
//                if ([pathDict.allKeys containsObject:e.to.value]) {
//                    NSNumber *weight = [pathDict valueForKey:e.to.value];
//                    if ([weight integerValue] <= newWeight) {
//                        continue;
//                    }
//                }
                
                NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
                NSInteger oldWeight = [[pathDict valueForKey:e.to.value] integerValue];
                if ([pathDict.allKeys containsObject:e.to.value] == NO || newWeight < oldWeight) {
                    NSArray *edges = [selectedEdgesDict valueForKey:minV.value];
                    NSMutableArray *mEdges = [[NSMutableArray alloc] initWithArray:edges];
                    [mEdges addObject:e];
                    [selectedEdgesDict setValue:mEdges forKey:e.to.value];
                    [pathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
                }
                

//                if ([pathDict.allKeys containsObject:e.to.value]) {
//                    NSNumber *weight = [pathDict valueForKey:e.to.value];
//                    NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
//                    if ([weight integerValue] > newWeight) {
//                        NSArray *edges = [selectedEdgesDict valueForKey:minV.value];
//                        NSMutableArray *mEdges = [[NSMutableArray alloc] initWithArray:edges];
//                        [mEdges addObject:e];
//                        [selectedEdgesDict setValue:mEdges forKey:e.to.value];
//
//                        [pathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
//                    }
//                } else {
//                    NSArray *edges = [selectedEdgesDict valueForKey:minV.value];
//                    NSMutableArray *mEdges = [[NSMutableArray alloc] initWithArray:edges];
//                    [mEdges addObject:e];
//                    [selectedEdgesDict setValue:mEdges forKey:e.to.value];
//
//                    NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
//                    [pathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
//                }
            }
        }
    }
    
    [selectedPathDict removeObjectForKey:beginVertex.value];
    [selectedEdgesDict removeObjectForKey:beginVertex.value];

    for (NSString *vertex in selectedEdgesDict.allKeys) {
        NSLog(@"%@", vertex);
        NSLog(@"%@", [selectedPathDict valueForKey:vertex]);
        NSLog(@"%@", [selectedEdgesDict valueForKey:vertex]);
    }
}

//// 最短路径
//- (void)dijkstra:(NSString *)begin {
//    Vertex *beginVertex = [self.vertexes valueForKey:begin];
//    if (beginVertex == nil) {
//        return;
//    }
//
//    NSMutableDictionary *pathDict = [[NSMutableDictionary alloc] init];
//    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
//
//    // 第一步 把起点的所有outEdges加入
//    // 更新到路径表中
//    for (Edge *e in beginVertex.outEdges) {
//        [pathDict setValue:e.weight forKey:e.to.value];
//    }
//
//    // 第二步 从路径表中 找到最小权重的边
//    while (pathDict.count > 0) {
//        Vertex *minV = nil;
//        NSNumber *minWeight = nil;
//        for (NSString *key in pathDict.allKeys) {
//            NSNumber *weight = [pathDict valueForKey:key];
//            if (minWeight == nil || [weight integerValue] < [minWeight integerValue]) {
//                minWeight = weight;
//                minV = [self.vertexes valueForKey:key];
//            }
//        }
//
//        if (minV != nil) {
//            [pathDict removeObjectForKey:minV.value];
//            [selectedPathDict setValue:minWeight forKey:minV.value];
//
//            // 第三步 遍历当前顶点的outEdges 进行松弛操作
//            for (Edge *e in minV.outEdges) {
//                if ([selectedPathDict.allKeys containsObject:e.to.value] || [e.to.value isEqualToString:beginVertex.value]) {
//                    continue;
//                }
//
//                if ([pathDict.allKeys containsObject:e.to.value]) {
//                    NSNumber *weight = [pathDict valueForKey:e.to.value];
//                    NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
//                    if ([weight integerValue] > newWeight) {
//                        [pathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
//                    }
//                } else {
//                    NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
//                    [pathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
//                }
//            }
//        }
//    }
//
//    NSLog(@"%@", pathDict);
//    NSLog(@"%@", selectedPathDict);
//
//}



- (void)bellmanFord:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }
    
    // [vertex.value: weight]
    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
    // [vertex.value: [edge]]
    NSMutableDictionary *selectedEdgesDict = [[NSMutableDictionary alloc] init];
    
    // 把起点给默认值0
    [selectedPathDict setValue:@0 forKey:begin];

    NSInteger count = self.vertexes.count;
    // 松弛n-1次(n是顶点的个数)
    for (NSInteger i = 0; i < count; i++) {
        for (Edge *e in self.edges) {
            
            // 如果这条边的起点的最短路径没有 那就直接返回
            // A->B->C
            // 如果现在松弛B->C 需要A->B已经确认了
            if ([selectedPathDict.allKeys containsObject:e.from.value] == NO) {
                continue;
            }
            
            NSNumber *minWeight = [selectedPathDict valueForKey:e.from.value];
            NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
            NSInteger oldWeight = [[selectedPathDict valueForKey:e.to.value] integerValue];
            
            // 如果之前没有松弛 或者之前权重值比当前值大
            if ([selectedPathDict.allKeys containsObject:e.to.value] == NO || newWeight < oldWeight) {
                NSArray *edges = [selectedEdgesDict valueForKey:e.from.value];
                NSMutableArray *mEdges = [[NSMutableArray alloc] initWithArray:edges];
                [mEdges addObject:e];
                [selectedEdgesDict setValue:mEdges forKey:e.to.value];
                [selectedPathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
            }
        }
    }
    
    // n-1次松弛后会确认每个顶点的最短路径
    // 如果有边还能再松弛一次 那就是有负权环
    for (Edge *e in self.edges) {
        if ([selectedPathDict.allKeys containsObject:e.from.value] == NO) {
            continue;
        }
        NSNumber *minWeight = [selectedPathDict valueForKey:e.from.value];
        NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
        NSInteger oldWeight = [[selectedPathDict valueForKey:e.to.value] integerValue];
        if ([selectedPathDict.allKeys containsObject:e.to.value] == NO || newWeight < oldWeight) {
            // 有负权环
            NSLog(@"有负权环");
            return;
        }
    }
    
    [selectedPathDict removeObjectForKey:beginVertex.value];
    [selectedEdgesDict removeObjectForKey:beginVertex.value];

    for (NSString *vertex in selectedEdgesDict.allKeys) {
        NSLog(@"%@", vertex);
        NSLog(@"%@", [selectedPathDict valueForKey:vertex]);
        NSLog(@"%@", [selectedEdgesDict valueForKey:vertex]);
    }
}

@end
