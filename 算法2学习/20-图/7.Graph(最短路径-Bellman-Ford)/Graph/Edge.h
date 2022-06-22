//
//  Edge.h
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import <Foundation/Foundation.h>
#import "Vertex.h"

NS_ASSUME_NONNULL_BEGIN

@interface Edge: NSObject

@property (nonatomic, strong) Vertex *from;
@property (nonatomic, strong) Vertex *to;
@property (nonatomic, strong) NSNumber *weight;

@end

NS_ASSUME_NONNULL_END
