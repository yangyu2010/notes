//
//  main.m
//  Graph
//
//  Created by Yu Yang on 6/7/22.
//

#import <Foundation/Foundation.h>
#import "ListGraph.h"
#import "FindUnion.h""

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

/// 拓扑排序
void test7() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"V1" to:@"V0" widget:@9];
    [graph addEdgeFrom:@"V1" to:@"V2" widget:@3];
    [graph addEdgeFrom:@"V2" to:@"V0" widget:@2];
    [graph addEdgeFrom:@"V2" to:@"V3" widget:@5];
    [graph addEdgeFrom:@"V3" to:@"V4" widget:@1];
    [graph addEdgeFrom:@"V0" to:@"V4" widget:@6];
    
    NSArray *array = [graph topologicalSort];
    NSLog(@"%@", array);
}

/// 拓扑排序
void test8() {
    ListGraph *graph = [[ListGraph alloc] init];
//
//    {0, 2},
//                {1, 0},
//                {2, 5}, {2, 6},
//                {3, 1}, {3, 5}, {3, 7},
//                {5, 7},
//                {6, 4},
//                {7, 6}
  
    [graph addEdgeFrom:@"0" to:@"2"];
    
    [graph addEdgeFrom:@"1" to:@"0"];

    [graph addEdgeFrom:@"2" to:@"5"];
    [graph addEdgeFrom:@"2" to:@"6"];

    [graph addEdgeFrom:@"3" to:@"1"];
    [graph addEdgeFrom:@"3" to:@"5"];
    [graph addEdgeFrom:@"3" to:@"7"];
    
    [graph addEdgeFrom:@"5" to:@"7"];
    [graph addEdgeFrom:@"6" to:@"4"];
    [graph addEdgeFrom:@"7" to:@"6"];

    NSArray *array = [graph topologicalSort];
    NSLog(@"%@", array);
}

/// 拓扑排序
void test9() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"V1" to:@"V2"];
    [graph addEdgeFrom:@"V1" to:@"V3"];
    [graph addEdgeFrom:@"V1" to:@"V4"];
    [graph addEdgeFrom:@"V2" to:@"V5"];
    [graph addEdgeFrom:@"V3" to:@"V5"];
    [graph addEdgeFrom:@"V4" to:@"V6"];
    [graph addEdgeFrom:@"V5" to:@"V7"];
    [graph addEdgeFrom:@"V5" to:@"V8"];
    [graph addEdgeFrom:@"V6" to:@"V8"];
    [graph addEdgeFrom:@"V7" to:@"V9"];
    [graph addEdgeFrom:@"V8" to:@"V9"];
    [graph addEdgeFrom:@"V9" to:@"V10"];

    NSArray *array = [graph topologicalSort];
    NSLog(@"%@", array);
}


/// Prim Kruskal 最小生成树 mst_03.jpg
void test10() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"B" widget:@4];
    [graph addEdgeFrom:@"B" to:@"A" widget:@4];
    
    [graph addEdgeFrom:@"A" to:@"H" widget:@8];
    [graph addEdgeFrom:@"H" to:@"A" widget:@8];
    
    [graph addEdgeFrom:@"B" to:@"H" widget:@11];
    [graph addEdgeFrom:@"H" to:@"B" widget:@11];
    
    [graph addEdgeFrom:@"B" to:@"C" widget:@8];
    [graph addEdgeFrom:@"C" to:@"B" widget:@8];
    
    [graph addEdgeFrom:@"C" to:@"I" widget:@2];
    [graph addEdgeFrom:@"I" to:@"C" widget:@2];

    [graph addEdgeFrom:@"H" to:@"I" widget:@7];
    [graph addEdgeFrom:@"I" to:@"H" widget:@7];

    [graph addEdgeFrom:@"G" to:@"I" widget:@6];
    [graph addEdgeFrom:@"I" to:@"G" widget:@6];

    [graph addEdgeFrom:@"G" to:@"H" widget:@1];
    [graph addEdgeFrom:@"H" to:@"G" widget:@1];

    [graph addEdgeFrom:@"G" to:@"F" widget:@2];
    [graph addEdgeFrom:@"F" to:@"G" widget:@2];

    [graph addEdgeFrom:@"C" to:@"D" widget:@7];
    [graph addEdgeFrom:@"D" to:@"C" widget:@7];
    
    [graph addEdgeFrom:@"C" to:@"F" widget:@4];
    [graph addEdgeFrom:@"F" to:@"C" widget:@4];

    [graph addEdgeFrom:@"D" to:@"F" widget:@14];
    [graph addEdgeFrom:@"F" to:@"D" widget:@14];

    [graph addEdgeFrom:@"D" to:@"E" widget:@9];
    [graph addEdgeFrom:@"E" to:@"D" widget:@9];

    [graph addEdgeFrom:@"F" to:@"E" widget:@10];
    [graph addEdgeFrom:@"E" to:@"F" widget:@10];

    [graph debugLog];
//        [graph bfs:@"A"];
//        [graph dfs:@"A"];
    [graph prim];
    [graph kruskal];

}


/// prim 最小生成树  (图mst_01.png)
void test11() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"0" to:@"2" widget:@2];
    [graph addEdgeFrom:@"2" to:@"0" widget:@2];
    [graph addEdgeFrom:@"0" to:@"4" widget:@7];
    [graph addEdgeFrom:@"4" to:@"0" widget:@7];

    [graph addEdgeFrom:@"1" to:@"2" widget:@3];
    [graph addEdgeFrom:@"2" to:@"1" widget:@3];
    [graph addEdgeFrom:@"1" to:@"5" widget:@1];
    [graph addEdgeFrom:@"5" to:@"1" widget:@1];
    [graph addEdgeFrom:@"1" to:@"6" widget:@7];
    [graph addEdgeFrom:@"6" to:@"1" widget:@7];

    [graph addEdgeFrom:@"2" to:@"4" widget:@4];
    [graph addEdgeFrom:@"4" to:@"2" widget:@4];
    [graph addEdgeFrom:@"2" to:@"5" widget:@3];
    [graph addEdgeFrom:@"5" to:@"2" widget:@3];
    [graph addEdgeFrom:@"2" to:@"6" widget:@6];
    [graph addEdgeFrom:@"6" to:@"2" widget:@6];

    [graph addEdgeFrom:@"3" to:@"7" widget:@9];
    [graph addEdgeFrom:@"7" to:@"3" widget:@9];

    [graph addEdgeFrom:@"4" to:@"6" widget:@8];
    [graph addEdgeFrom:@"6" to:@"4" widget:@8];

    [graph addEdgeFrom:@"5" to:@"6" widget:@4];
    [graph addEdgeFrom:@"6" to:@"5" widget:@4];
    [graph addEdgeFrom:@"5" to:@"7" widget:@5];
    [graph addEdgeFrom:@"7" to:@"5" widget:@5];

    /*
    {0, 2, 2}, {0, 4, 7},
                {1, 2, 3}, {1, 5, 1}, {1, 6, 7},
                {2, 4, 4}, {2, 5, 3}, {2, 6, 6},
                {3, 7, 9},
                {4, 6, 8},
                {5, 6, 4}, {5, 7, 5}
     */
    
    [graph debugLog];
    
    [graph prim];
    [graph kruskal];
}


/// prim 最小生成树  (图mst_02.png)
void test12() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"B" widget:@17];
    [graph addEdgeFrom:@"B" to:@"A" widget:@17];
    [graph addEdgeFrom:@"A" to:@"F" widget:@1];
    [graph addEdgeFrom:@"F" to:@"A" widget:@1];
    [graph addEdgeFrom:@"A" to:@"E" widget:@16];
    [graph addEdgeFrom:@"E" to:@"A" widget:@16];

    [graph addEdgeFrom:@"B" to:@"C" widget:@6];
    [graph addEdgeFrom:@"C" to:@"B" widget:@6];
    [graph addEdgeFrom:@"B" to:@"D" widget:@5];
    [graph addEdgeFrom:@"D" to:@"B" widget:@5];
    [graph addEdgeFrom:@"B" to:@"F" widget:@11];
    [graph addEdgeFrom:@"F" to:@"B" widget:@11];

    [graph addEdgeFrom:@"D" to:@"C" widget:@10];
    [graph addEdgeFrom:@"C" to:@"D" widget:@10];

    [graph addEdgeFrom:@"D" to:@"E" widget:@4];
    [graph addEdgeFrom:@"E" to:@"D" widget:@4];
    [graph addEdgeFrom:@"D" to:@"F" widget:@14];
    [graph addEdgeFrom:@"F" to:@"D" widget:@14];

    [graph addEdgeFrom:@"E" to:@"F" widget:@33];
    [graph addEdgeFrom:@"F" to:@"E" widget:@33];
    
    [graph debugLog];
    
    [graph prim];
    [graph kruskal];
//    {"A", "B", 17}, {"A", "F", 1}, {"A", "E", 16},
//    {"B", "C", 6}, {"B", "D", 5}, {"B", "F", 11},
//    {"C", "D", 10},
//    {"D", "E", 4}, {"D", "F", 14},
//    {"E", "F", 33}
}


/// 测试并查集
void test13() {
    FindUnion *fu = [[FindUnion alloc] initWithCapacity:20];
    for (NSInteger i = 0; i < 12; i++) {
        [fu set:[NSString stringWithFormat:@"%ld", i]];
    }

    [fu union2:@"0" v2:@"1"];
    [fu union2:@"0" v2:@"3"];
    [fu union2:@"0" v2:@"4"];
    [fu union2:@"2" v2:@"3"];
    [fu union2:@"2" v2:@"5"];
    [fu union2:@"3" v2:@"3"];

    [fu union2:@"6" v2:@"7"];

    [fu union2:@"8" v2:@"9"];
    [fu union2:@"8" v2:@"10"];
    [fu union2:@"9" v2:@"10"];
    [fu union2:@"9" v2:@"11"];

    assert([fu isSame:@"0" v2:@"1"] == YES);
    assert([fu isSame:@"0" v2:@"6"] == NO);
    assert([fu isSame:@"0" v2:@"7"] == NO);
    assert([fu isSame:@"1" v2:@"7"] == NO);
    assert([fu isSame:@"2" v2:@"7"] == NO);
    assert([fu isSame:@"3" v2:@"7"] == NO);
    assert([fu isSame:@"4" v2:@"7"] == NO);
    assert([fu isSame:@"5" v2:@"7"] == NO);
    assert([fu isSame:@"6" v2:@"7"] == YES);
    assert([fu isSame:@"8" v2:@"9"] == YES);
    assert([fu isSame:@"9" v2:@"10"] == YES);
    assert([fu isSame:@"10" v2:@"11"] == YES);
    assert([fu isSame:@"8" v2:@"11"] == YES);
    assert([fu isSame:@"6" v2:@"8"] == NO);
    assert([fu isSame:@"6" v2:@"9"] == NO);
    assert([fu isSame:@"6" v2:@"10"] == NO);
    assert([fu isSame:@"6" v2:@"11"] == NO);

    [fu union2:@"1" v2:@"6"];
    
    assert([fu isSame:@"0" v2:@"6"] == YES);
    assert([fu isSame:@"0" v2:@"7"] == YES);
    assert([fu isSame:@"1" v2:@"7"] == YES);
    assert([fu isSame:@"2" v2:@"7"] == YES);
    assert([fu isSame:@"3" v2:@"7"] == YES);
    assert([fu isSame:@"4" v2:@"7"] == YES);
    assert([fu isSame:@"5" v2:@"7"] == YES);

    [fu union2:@"7" v2:@"8"];
    
    assert([fu isSame:@"0" v2:@"8"] == YES);
    assert([fu isSame:@"0" v2:@"9"] == YES);
    assert([fu isSame:@"1" v2:@"10"] == YES);
    assert([fu isSame:@"2" v2:@"11"] == YES);
    assert([fu isSame:@"3" v2:@"10"] == YES);
    assert([fu isSame:@"4" v2:@"10"] == YES);
    assert([fu isSame:@"5" v2:@"11"] == YES);

}

/// 最短路径 Dijkstra (图片sp1)
void test14() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"E" widget:@100];
    [graph addEdgeFrom:@"A" to:@"D" widget:@30];
    [graph addEdgeFrom:@"A" to:@"B" widget:@10];
    [graph addEdgeFrom:@"B" to:@"C" widget:@50];
    [graph addEdgeFrom:@"C" to:@"E" widget:@10];
    [graph addEdgeFrom:@"D" to:@"C" widget:@20];
    [graph addEdgeFrom:@"D" to:@"E" widget:@60];

    // 图Xnip2022-06-07_18-27-19.jpg
//    [graph addEdgeFrom:@"V1" to:@"V0" widget:@9];
//    [graph addEdgeFrom:@"V1" to:@"V2" widget:@3];
//    [graph addEdgeFrom:@"V2" to:@"V0" widget:@2];
//    [graph addEdgeFrom:@"V2" to:@"V3" widget:@5];
//    [graph addEdgeFrom:@"V3" to:@"V4" widget:@1];
//    [graph addEdgeFrom:@"V0" to:@"V4" widget:@6];
    
//    [graph debugLog];
    
//    [graph dijkstra:@"A"];
//    [graph bellmanFord:@"A"];
    
//    [graph bellmanFord:@"V1"];
}

/// 最短路径 Dijkstra  (图mst_03.png)
void test15() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"B" widget:@4];
    [graph addEdgeFrom:@"B" to:@"A" widget:@4];
    
    [graph addEdgeFrom:@"A" to:@"H" widget:@8];
    [graph addEdgeFrom:@"H" to:@"A" widget:@8];
    
    [graph addEdgeFrom:@"B" to:@"H" widget:@11];
    [graph addEdgeFrom:@"H" to:@"B" widget:@11];
    
    [graph addEdgeFrom:@"B" to:@"C" widget:@8];
    [graph addEdgeFrom:@"C" to:@"B" widget:@8];
    
    [graph addEdgeFrom:@"C" to:@"I" widget:@2];
    [graph addEdgeFrom:@"I" to:@"C" widget:@2];

    [graph addEdgeFrom:@"H" to:@"I" widget:@7];
    [graph addEdgeFrom:@"I" to:@"H" widget:@7];

    [graph addEdgeFrom:@"G" to:@"I" widget:@6];
    [graph addEdgeFrom:@"I" to:@"G" widget:@6];

    [graph addEdgeFrom:@"G" to:@"H" widget:@1];
    [graph addEdgeFrom:@"H" to:@"G" widget:@1];

    [graph addEdgeFrom:@"G" to:@"F" widget:@2];
    [graph addEdgeFrom:@"F" to:@"G" widget:@2];

    [graph addEdgeFrom:@"C" to:@"D" widget:@7];
    [graph addEdgeFrom:@"D" to:@"C" widget:@7];
    
    [graph addEdgeFrom:@"C" to:@"F" widget:@4];
    [graph addEdgeFrom:@"F" to:@"C" widget:@4];

    [graph addEdgeFrom:@"D" to:@"F" widget:@14];
    [graph addEdgeFrom:@"F" to:@"D" widget:@14];

    [graph addEdgeFrom:@"D" to:@"E" widget:@9];
    [graph addEdgeFrom:@"E" to:@"D" widget:@9];

    [graph addEdgeFrom:@"F" to:@"E" widget:@10];
    [graph addEdgeFrom:@"E" to:@"F" widget:@10];
    
//    [graph dijkstra:@"A"];
    [graph bellmanFord:@"A"];
}


/// 最短路径 (图negative_weight_01.png)
void test16() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"A" to:@"B" widget:@-1];
    [graph addEdgeFrom:@"A" to:@"C" widget:@4];
    [graph addEdgeFrom:@"B" to:@"C" widget:@3];
    [graph addEdgeFrom:@"B" to:@"D" widget:@2];
    [graph addEdgeFrom:@"B" to:@"E" widget:@2];
    [graph addEdgeFrom:@"D" to:@"B" widget:@1];
    [graph addEdgeFrom:@"D" to:@"C" widget:@5];
    [graph addEdgeFrom:@"E" to:@"D" widget:@-3];
    
//    [graph dijkstra:@"A"];
    [graph bellmanFord:@"A"];
}

/// 最短路径 (图negative_weight_02.png)
void test17() {
    ListGraph *graph = [[ListGraph alloc] init];
    [graph addEdgeFrom:@"0" to:@"1" widget:@1];
    [graph addEdgeFrom:@"1" to:@"0" widget:@-2];
    [graph addEdgeFrom:@"1" to:@"2" widget:@7];

    [graph dijkstra:@"0"];
//    [graph bellmanFord:@"0"];
}

int main(int argc, const char * argv[]) {
    
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    test10();
//    test11();
//    test12();
//    test13();
    
//    test14();
//    test15();
    
    test16();
//    test17();
        
        
    return 0;
}




