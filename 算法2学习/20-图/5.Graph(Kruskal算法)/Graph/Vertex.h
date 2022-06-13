//
//  Vertex.h
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Vertex : NSObject

@property (nonatomic, strong) NSString *value;
@property (nonatomic, strong) NSMutableSet *inEdges;
@property (nonatomic, strong) NSMutableSet *outEdges;

@end

NS_ASSUME_NONNULL_END
