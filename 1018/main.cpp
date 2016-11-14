//
//  main.cpp
//  1018
//
//  Created by huangsunyang on 9/21/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;
struct near {
    int start, end, length;
    near(int st, int ed, int len): start(st), end(ed), length(len){}
    bool operator < (const near& a) const {
        return length > a.length;
    }
};
struct node {
    int index = 0;
    int contribution = 0;
    int requirement = 0;
    bool has_found = true;
    int current_shortest = 0;
    int privious_point = -1;
    int accumulation = 0;
    int require_accumulation = 0;
    vector<near> near_nodes;
    node() {}
    node(int in, int crt_size, int k): index(in), contribution(crt_size), has_found(false), current_shortest(0x0FFFFFFF), requirement(k){}
};

void print(vector<node> a, int n) {
    if (n == 0) {
        printf("0");
    } else {
        print(a, a[n].privious_point);
        printf("->%d", n);
    }
}
priority_queue<near> que;
void relax(node& b, node& a, int edge) {
    if (a.current_shortest > b.current_shortest + edge) {
        a.current_shortest = b.current_shortest + edge;
        a.accumulation = max(b.accumulation + a.contribution - a.requirement, 0);
        a.require_accumulation = b.require_accumulation + max(a.requirement - b.accumulation, 0);
        a.privious_point = b.index;
        que.push(near(b.index, a.index, a.current_shortest));
    } else if(a.current_shortest == b.current_shortest + edge) {
        if (a.require_accumulation > b.require_accumulation + max(a.requirement - b.accumulation, 0)) {
            a.accumulation = max(b.accumulation + a.contribution - a.requirement, 0);
            a.require_accumulation = b.require_accumulation + max(a.requirement - b.accumulation, 0);
            a.privious_point = b.index;
        } else if(a.require_accumulation == b.require_accumulation + max(a.requirement - b.accumulation, 0)) {
            if (a.accumulation > max(b.accumulation + a.contribution - a.requirement, 0)) {
                a.accumulation = max(b.accumulation + a.contribution - a.requirement, 0);
                a.privious_point = b.index;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    vector<node> nodes;
    int capacity, n, problem_num, road_num, crt_size, start, end, length;
    scanf("%d %d %d %d", &capacity, &n, &problem_num, &road_num);
    nodes.push_back(node(0, 0, 0));
    nodes[0].has_found = true;
    nodes[0].current_shortest = 0;
    nodes[0].accumulation = nodes[0].contribution;
    //接受所有的点的信息
    for (int i = 1; i <= n; i++) {
        scanf("%d", &crt_size);
        nodes.push_back(node(i, max(crt_size - capacity / 2, 0), max(0, capacity / 2 - crt_size)));
    }
    //对每一个点都维护它的后续节点
    for (int i = 0; i < road_num; i++) {
        scanf("%d %d %d", &start, &end, &length);
        nodes[start].near_nodes.push_back(near(start, end, length));
        nodes[end].near_nodes.push_back(near(start, end, length));
    }
    //从源节点开始
    int start_point = 0;
    while (n > 0) {    //n代表还没有找到最短路径的点的数量
        for (int i = 0; i < nodes[start_point].near_nodes.size(); i++) {    //对其所有相邻节点
            relax(nodes[start_point], nodes[nodes[start_point].near_nodes[i].end], nodes[start_point].near_nodes[i].length);
        }
        while (!que.empty() && nodes[que.top().end].has_found) {
            que.pop();
        }
        start_point = que.top().end;
        nodes[start_point].has_found = true;
        que.pop();
        n--;
    }
    printf("%d ", nodes[problem_num].require_accumulation);
    print(nodes, problem_num);
    printf(" %d", nodes[problem_num].accumulation);
    return 0;
}
