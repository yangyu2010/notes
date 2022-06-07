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
- (void)addEdgeFrom:(NSString *)vertex1 to:(NSString *)vertex2;
- (void)addEdgeFrom:(NSString *)vertex1 to:(NSString *)vertex2 widget:(nullable NSNumber *)weight;

- (void)removeVertex:(NSString *)vertex;
- (void)removeEdgeFrom:(NSString *)vertex1 to:(NSString *)vertex2;


@end

NS_ASSUME_NONNULL_END
