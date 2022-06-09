//
//  main.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import <Foundation/Foundation.h>
#import "ListGraph.h"


/// 测试图的基础功能 添加删除
void test1() {
    
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"V1" to:@"V0" widget:@9];
    [graph addEdgeFrom:@"V1" to:@"V2" widget:@3];
    [graph addEdgeFrom:@"V2" to:@"V0" widget:@2];
    [graph addEdgeFrom:@"V2" to:@"V3" widget:@5];
    [graph addEdgeFrom:@"V3" to:@"V4" widget:@1];
    [graph addEdgeFrom:@"V0" to:@"V4" widget:@6];
    
    [graph addEdgeFrom:@"V0" to:@"V4" widget:@16];
    [graph addEdgeFrom:@"V3" to:@"V4" widget:@10];
    
//    [graph removeVertex:@"V0"];
//    [graph removeVertex:@"V3"];
//    [graph removeVertex:@"v3"];
//    [graph removeVertex:@"v1"];
//    [graph removeVertex:@"V1"];

//    [graph removeEdgeFrom:@"V1" to:@"V2"];
//    [graph removeEdgeFrom:@"V1" to:@"V2"];
//    [graph removeEdgeFrom:@"V1" to:@"V3"];
//    [graph removeEdgeFrom:@"V1" to:@"v3"];
    
//    [graph removeEdgeFrom:@"V1" to:@"V0"];
//    [graph removeEdgeFrom:@"V2" to:@"V0"];
//    [graph removeEdgeFrom:@"V0" to:@"V4"];


    [graph debugLog];
}




int main(int argc, const char * argv[]) {
    
    test1();

    
    return 0;
}




