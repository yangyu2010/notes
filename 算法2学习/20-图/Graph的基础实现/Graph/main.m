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

/// 测试图的bfs dfs
void test2() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"V1" to:@"V0" widget:@9];
    [graph addEdgeFrom:@"V1" to:@"V2" widget:@3];
    [graph addEdgeFrom:@"V2" to:@"V0" widget:@2];
    [graph addEdgeFrom:@"V2" to:@"V3" widget:@5];
    [graph addEdgeFrom:@"V3" to:@"V4" widget:@1];
    [graph addEdgeFrom:@"V0" to:@"V4" widget:@6];
    
//    [graph addEdgeFrom:@"V0" to:@"V4" widget:@16];
//    [graph addEdgeFrom:@"V3" to:@"V4" widget:@10];
    
//    [graph bfs:@"V1"];
//    [graph debugLog];
    [graph dfs:@"V1"];
}

/// 测试图的bfs dfs
void test3() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"B"];
    [graph addEdgeFrom:@"B" to:@"A"];

    [graph addEdgeFrom:@"A" to:@"F"];
    [graph addEdgeFrom:@"F" to:@"A"];
    
    [graph addEdgeFrom:@"B" to:@"G"];
    [graph addEdgeFrom:@"G" to:@"B"];
    
    [graph addEdgeFrom:@"B" to:@"C"];
    [graph addEdgeFrom:@"C" to:@"B"];
    
    [graph addEdgeFrom:@"B" to:@"I"];
    [graph addEdgeFrom:@"I" to:@"B"];
    
    [graph addEdgeFrom:@"C" to:@"I"];
    [graph addEdgeFrom:@"I" to:@"C"];

    [graph addEdgeFrom:@"D" to:@"C"];
    [graph addEdgeFrom:@"C" to:@"D"];

    [graph addEdgeFrom:@"I" to:@"D"];
    [graph addEdgeFrom:@"D" to:@"I"];

    [graph addEdgeFrom:@"G" to:@"D"];
    [graph addEdgeFrom:@"D" to:@"G"];

    [graph addEdgeFrom:@"G" to:@"F"];
    [graph addEdgeFrom:@"F" to:@"G"];
    
    [graph addEdgeFrom:@"G" to:@"H"];
    [graph addEdgeFrom:@"H" to:@"G"];

    [graph addEdgeFrom:@"F" to:@"E"];
    [graph addEdgeFrom:@"E" to:@"F"];

    [graph addEdgeFrom:@"H" to:@"E"];
    [graph addEdgeFrom:@"E" to:@"H"];

    [graph addEdgeFrom:@"H" to:@"D"];
    [graph addEdgeFrom:@"D" to:@"H"];

    [graph addEdgeFrom:@"D" to:@"E"];
    [graph addEdgeFrom:@"E" to:@"D"];
    
//    [graph debugLog];
    
//    [graph bfs:@"A"];
    [graph dfs:@"A"];
}


/// 测试图的bfs dfs
void test4() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"0" to:@"1"];
    [graph addEdgeFrom:@"0" to:@"4"];
    
    [graph addEdgeFrom:@"5" to:@"3"];
    [graph addEdgeFrom:@"5" to:@"7"];

    [graph addEdgeFrom:@"6" to:@"2"];
    [graph addEdgeFrom:@"6" to:@"7"];
    
    [graph addEdgeFrom:@"1" to:@"2"];
    
    [graph addEdgeFrom:@"3" to:@"1"];

    [graph addEdgeFrom:@"4" to:@"6"];
    [graph addEdgeFrom:@"4" to:@"7"];
    
    [graph addEdgeFrom:@"2" to:@"0"];
    [graph addEdgeFrom:@"2" to:@"4"];
    [graph addEdgeFrom:@"2" to:@"5"];
    
//    [graph debugLog];
//    [graph bfs:@"0"];
    [graph dfs:@"0"];
}

/// 测试图的bfs dfs
void test5() {
    ListGraph *graph = [[ListGraph alloc] init];
    
    [graph addEdgeFrom:@"0" to:@"1"];
    
    [graph addEdgeFrom:@"1" to:@"3"];
    [graph addEdgeFrom:@"1" to:@"5"];
    [graph addEdgeFrom:@"1" to:@"6"];
    [graph addEdgeFrom:@"1" to:@"2"];
    
    [graph addEdgeFrom:@"2" to:@"4"];
    
    [graph addEdgeFrom:@"3" to:@"7"];

//    [graph debugLog];
//    [graph bfs:@"0"];
    [graph dfs:@"0"];
}

/// 测试图的bfs dfs
void test6() {
    ListGraph *graph = [[ListGraph alloc] init];
    
    [graph addEdgeFrom:@"a" to:@"b"];
    [graph addEdgeFrom:@"a" to:@"e"];
    
    [graph addEdgeFrom:@"b" to:@"e"];
    [graph addEdgeFrom:@"c" to:@"b"];
    [graph addEdgeFrom:@"d" to:@"a"];
    
    [graph addEdgeFrom:@"e" to:@"c"];
    
    [graph addEdgeFrom:@"e" to:@"f"];
    [graph addEdgeFrom:@"f" to:@"c"];

//    [graph debugLog];
//    [graph bfs:@"0"];
    [graph dfs:@"a"];
}

int main(int argc, const char * argv[]) {
    
//    test1();
    test2();
//    test3();
//    test4();
//    test5();
    
//    test6();
    
    return 0;
}




