//
//  ListGraph.h
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ListGraph : NSObject

- (void)debugLog;
- (NSInteger)edgesSize;
- (NSInteger)vertexesSize;

- (void)addVertex:(NSString *)vertex;
- (void)addEdgeFrom:(NSString *)from to:(NSString *)to;
- (void)addEdgeFrom:(NSString *)from to:(NSString *)to widget:(nullable NSNumber *)weight;

- (void)removeVertex:(NSString *)vertex;
- (void)removeEdgeFrom:(NSString *)from to:(NSString *)to;

- (void)bfs:(NSString *)begin;
- (void)dfs:(NSString *)begin;
- (NSArray<NSString *> *)topologicalSort;

// 最小生成树
- (void)prim;
- (void)kruskal;

// 最短路径
- (void)dijkstra:(NSString *)begin;;
- (void)bellmanFord:(NSString *)begin;
- (void)floyd;

@end

NS_ASSUME_NONNULL_END
