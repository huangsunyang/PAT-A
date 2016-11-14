//
//  main.cpp
//  1003
//
//  Created by huangsunyang on 8/29/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MAX 2147483647
using namespace std;

class node {
public:
    int end, value;
    node(int x, int y): end(x), value(y){}
    bool operator< (const node o) const {
        return value > o.value;
    }
    bool operator> (const node o) const {
        return value < o.value;
    }
};

void relax(int u, int v, vector<vector<int> > w, vector<int>& dshort, vector<int>& rescue, vector<int> fireman, priority_queue<node> &my_heap, vector<int> &ways) {
    if (dshort[v] > dshort[u] + w[u][v]) {
        dshort[v] = dshort[u] + w[u][v];
        rescue[v] = rescue[u] + fireman[v];
        my_heap.push(node(v, dshort[v]));
        ways[v] = ways[u];
    }
    else if (dshort[v] == dshort[u] + w[u][v]) {
        rescue[v] = max(rescue[u] + fireman[v], rescue[v]);
        ways[v] += ways[u];
    }
}

int main(int argc, const char * argv[]) {
    int nodes, edges, my_pos, des_pos;
    int start, end, value;
    scanf("%d %d %d %d", &nodes, &edges, &my_pos, &des_pos);
    vector<int> fireman_num(nodes);         //每个城市的人数
    vector<int> dshort(nodes);              //暂时最短路径
    vector<bool> in_set(nodes, false);      //记录是否已经求出最短距离
    vector<int> ways(nodes, 0);             //最短路径的数量
    ways[my_pos] = 1;
    in_set[my_pos] = true;
    for (int i = 0; i < nodes; i++) {
        scanf("%d", &fireman_num[i]);
    }
    
    //初始化暂时最短路径
    for (int i = 0; i < nodes; i++) {
        dshort[i] = MAX;
    }
    dshort[my_pos] = 0;
    //初始化完毕
    
    //建立图，最普通的矩阵表示
    vector<vector<int> > graph(nodes);
    for (int i = 0; i < nodes; i++) {
        graph[i] = vector<int>(nodes, -1);
    }
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &start, &end, &value);
        graph[start][end] = value;
        graph[end][start] = value;
    }
    //图建立完毕
    
    priority_queue<node> my_heap;   //建立最小堆
    //初始化最大集合人数
    vector<int> max_rescues(nodes);
    for (int i = 0; i < nodes; i++) {
        max_rescues[i] = fireman_num[i];
    }
    //初始化完毕
    int shortest_pos = my_pos;
    while (shortest_pos != des_pos) {
        int i = shortest_pos;
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] > 0 && !in_set[j]) {
                relax(i, j, graph, dshort, max_rescues, fireman_num, my_heap, ways);
            }
        }
        //确保不重复边，比如源s到某一点v有许多路径都很短，它门都会聚集在堆顶，但是此时需要删除他么
        while (in_set[my_heap.top().end]) {
            my_heap.pop();
        }
        shortest_pos = my_heap.top().end;
        my_heap.pop();
        in_set[shortest_pos] = true;
    }
    printf("%d %d", ways[des_pos], max_rescues[des_pos]);
    return 0;
}
