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
    
    /// ???iOS????????????????????????????????? ??????????????????????????????
    /// ????????????????????? ?????????????????????
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
 dfs????????????
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

    /// ???iOS?????????????????????????????? ??????????????????????????????
    /// ????????????
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
    
    // ???????????????????????????
    NSMutableSet<Vertex *> *vertexSet = [[NSMutableSet alloc] init];
    [vertexSet addObject:beginVertex];

    // ???????????????????????? ?????????
    NSMutableSet<Edge *> *edgeSet = [[NSMutableSet alloc] init];
    
    // ??????????????????
    // ??????????????????Vertex???outEdges???
    NSMutableSet<Edge *> *edgeSetFor = [[NSMutableSet alloc] init];

    // ???????????? ????????????
    // Objective-C ??????????????????
    while (vertexSet.count != self.vertexes.count) {
        Vertex *searchV = nil;
        Edge *searchE = nil;
        
        for (Vertex *v in vertexSet) {
            [edgeSetFor addObjectsFromArray:v.outEdges.allObjects];
        }
        
        for (Edge *edge in edgeSetFor) {
            // ??????????????????????????????
            if ([edgeSet containsObject:edge]) {
                continue;
            }
            // ????????????????????????????????????????????????
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
    // ?????????????????????????????????????????????????????????????????????????????????????????????V-1???????????????V??????????????????
    // ????????????????????????????????????????????????????????????
    // ??????3?????????????????????????????????????????????

    // ???????????? ????????????
    // Objective-C ??????????????????
    NSMutableSet<Vertex *> *vertexSet = [[NSMutableSet alloc] init];
    NSMutableSet<Edge *> *edgeSet = [[NSMutableSet alloc] init];
    NSMutableSet<Edge *> *edgeSetFor = [[NSMutableSet alloc] initWithSet:self.edges];

    // ??????????????????
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
            
            // ???????????????????????????
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


// ????????????
- (void)dijkstra:(NSString *)begin {
    Vertex *beginVertex = [self.vertexes valueForKey:begin];
    if (beginVertex == nil) {
        return;
    }
    
    NSMutableDictionary *pathDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
    NSMutableDictionary *selectedEdgesDict = [[NSMutableDictionary alloc] init];

    // ????????? ??????????????????outEdges??????
    // ?????????????????????
//    for (Edge *e in beginVertex.outEdges) {
//        [pathDict setValue:e.weight forKey:e.to.value];
//        [selectedEdgesDict setValue:@[e] forKey:e.to.value];
//    }
    [pathDict setValue:@0 forKey:beginVertex.value];

    // ????????? ??????????????? ????????????????????????
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
            
            // ????????? ?????????????????????outEdges ??????????????????
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

//// ????????????
//- (void)dijkstra:(NSString *)begin {
//    Vertex *beginVertex = [self.vertexes valueForKey:begin];
//    if (beginVertex == nil) {
//        return;
//    }
//
//    NSMutableDictionary *pathDict = [[NSMutableDictionary alloc] init];
//    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
//
//    // ????????? ??????????????????outEdges??????
//    // ?????????????????????
//    for (Edge *e in beginVertex.outEdges) {
//        [pathDict setValue:e.weight forKey:e.to.value];
//    }
//
//    // ????????? ??????????????? ????????????????????????
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
//            // ????????? ?????????????????????outEdges ??????????????????
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
    
    // ?????????????????????0
    [selectedPathDict setValue:@0 forKey:begin];

    NSInteger count = self.vertexes.count;
    // ??????n-1???(n??????????????????)
    for (NSInteger i = 0; i < count; i++) {
        for (Edge *e in self.edges) {
            
            // ????????????????????????????????????????????? ??????????????????
            // A->B->C
            // ??????????????????B->C ??????A->B???????????????
            if ([selectedPathDict.allKeys containsObject:e.from.value] == NO) {
                continue;
            }
            
            NSNumber *minWeight = [selectedPathDict valueForKey:e.from.value];
            NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
            NSInteger oldWeight = [[selectedPathDict valueForKey:e.to.value] integerValue];
            
            // ???????????????????????? ????????????????????????????????????
            if ([selectedPathDict.allKeys containsObject:e.to.value] == NO || newWeight < oldWeight) {
                NSArray *edges = [selectedEdgesDict valueForKey:e.from.value];
                NSMutableArray *mEdges = [[NSMutableArray alloc] initWithArray:edges];
                [mEdges addObject:e];
                [selectedEdgesDict setValue:mEdges forKey:e.to.value];
                [selectedPathDict setValue:[NSNumber numberWithInteger:newWeight] forKey:e.to.value];
            }
        }
    }
    
    // n-1????????????????????????????????????????????????
    // ????????????????????????????????? ?????????????????????
    for (Edge *e in self.edges) {
        if ([selectedPathDict.allKeys containsObject:e.from.value] == NO) {
            continue;
        }
        NSNumber *minWeight = [selectedPathDict valueForKey:e.from.value];
        NSInteger newWeight = [minWeight integerValue] + [e.weight integerValue];
        NSInteger oldWeight = [[selectedPathDict valueForKey:e.to.value] integerValue];
        if ([selectedPathDict.allKeys containsObject:e.to.value] == NO || newWeight < oldWeight) {
            // ????????????
            NSLog(@"????????????");
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

- (void)floyd {
    
    // [vertex.value: [vertex.value: weight]]
    NSMutableDictionary *selectedPathDict = [[NSMutableDictionary alloc] init];
    // [vertex.value: [vertex.value: [edge]]]
    NSMutableDictionary *selectedEdgesDict = [[NSMutableDictionary alloc] init];

    for (Edge *e in self.edges) {
        NSDictionary *dict = [selectedPathDict valueForKey:e.from.value];
        NSMutableDictionary *m_dict;
        if (dict == nil) {
            m_dict = [[NSMutableDictionary alloc] init];
        } else {
            m_dict = [[NSMutableDictionary alloc] initWithDictionary:dict];
        }
        [m_dict setValue:e.weight forKey:e.to.value];
        [selectedPathDict setValue:m_dict forKey:e.from.value];
        
        NSDictionary *edgeDict = [selectedEdgesDict valueForKey:e.from.value];
        NSMutableDictionary *m_edgeDict;
        if (edgeDict == nil) {
            m_edgeDict = [[NSMutableDictionary alloc] init];
        } else {
            m_edgeDict = [[NSMutableDictionary alloc] initWithDictionary:edgeDict];
        }
        [m_edgeDict setValue:@[e] forKey:e.to.value];
        [selectedEdgesDict setValue:m_edgeDict forKey:e.from.value];
    }
    
    NSArray <Vertex *> *arrayVertexes = self.vertexes.allValues;
    
    for (NSInteger k = 0; k < arrayVertexes.count; k++) {
        for (NSInteger i = 0; i < arrayVertexes.count; i++) {
            for (NSInteger j = 0; j < arrayVertexes.count; j++) {
                Vertex *v_i = arrayVertexes[i];
                Vertex *v_k = arrayVertexes[k];
                Vertex *v_j = arrayVertexes[j];
                if ([v_i.value isEqual:v_k.value] || [v_i.value isEqualTo:v_j.value]) {
                    continue;
                }
                
                // i->k
                NSDictionary *dict_i = [selectedPathDict valueForKey:v_i.value];
                NSNumber *path_i_k = [dict_i valueForKey:v_k.value];
                if (path_i_k == nil) {
                    continue;
                }
                
                // k->j
                NSDictionary *dict_k = [selectedPathDict valueForKey:v_k.value];
                NSNumber *path_k_j = [dict_k valueForKey:v_j.value];
                if (path_k_j == nil) {
                    continue;
                }
                
                // i->j
                NSNumber *path_i_j = [dict_i valueForKey:v_j.value];
                
                if (path_i_j == nil || ([path_i_k integerValue] + [path_k_j integerValue] < [path_i_j integerValue])) {
                    NSMutableDictionary *m_dict_i = [[NSMutableDictionary alloc] initWithDictionary:dict_i];
                    [m_dict_i setValue:[NSNumber numberWithInteger:[path_i_k integerValue] + [path_k_j integerValue]] forKey:v_j.value];
                    [selectedPathDict setValue:m_dict_i forKey:v_i.value];
                    
                    
                    // i->k k->j
                    NSDictionary *dictPath_i = [selectedEdgesDict valueForKey:v_i.value];
                    NSArray *arrayPath_i_k = [dictPath_i valueForKey:v_k.value];
                    
                    NSDictionary *dictPath_k = [selectedEdgesDict valueForKey:v_k.value];
                    NSArray *arrayPath_k_j = [dictPath_k valueForKey:v_j.value];
                    
                    NSMutableArray *m_array_i_j = [[NSMutableArray alloc] initWithArray:arrayPath_i_k];
                    [m_array_i_j addObjectsFromArray:arrayPath_k_j];
                    
                    NSMutableDictionary *m_dictPath_i = [[NSMutableDictionary alloc] initWithDictionary:dictPath_i];
                    [m_dictPath_i setValue:m_array_i_j forKey:v_j.value];
                    
                    [selectedEdgesDict setValue:m_dictPath_i forKey:v_i.value];
                }
            }
        }
    }
    
    NSLog(@"%@", selectedPathDict);
    NSLog(@"%@", selectedEdgesDict);

}

@end
