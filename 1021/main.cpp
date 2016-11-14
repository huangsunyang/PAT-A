//
//  main.cpp
//  1021
//
//  Created by huangsunyang on 9/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct edge {
    int end, weight;
    edge(){}
    edge(int a, int b): end(a), weight(b){}
    bool operator< (const edge& b) const {
        return weight > b.weight || (weight == b.weight && end < b.end);
    }
};
const int SZ = 1 << 20;  //提升IO buff
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;
struct graph {
    vector<vector<int> > gr;
    int * has_found;
    int * depth;
    int num;
    graph(int n) {
        gr = vector<vector<int> >(n + 1);
        has_found = new int[n + 1];
        depth = new int[n + 1];
        num = n;
        memset(has_found, 0, n+1);
        memset(depth, 0, n+1);
//        for(int i = 0; i < n + 1; i++) {
//            has_found[i] = 0;
//            depth[i] = 0;
//        }
    }
    void print() {
        for (int i = 1; i < gr.size(); i++) {
            printf("%d: ", i);
            for (int j = 0; j < gr[i].size(); j++) {
                printf("%d ", gr[i][j]);
            }
            putchar('\n');
        }
    }
    void initial() {
        for(int i = 0; i < gr.size(); i++) {
            has_found[i] = 0;
            depth[i] = 0;
        }
    }
    void add_edge(int a, int b) {
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    
    int is_connected() {
        int count = 0;
        initial();
        for(int i = 1; i < gr.size(); i++) {
            if(has_found[i]) continue;
            ++count;
            bfs(i);
        }
        return count;
    }
    void bfs(int i) {
        queue<int> qe;
        qe.push(i);
        while(!qe.empty()) {
            int t = qe.front(), pos = 0;
            qe.pop();
            while(pos < gr[t].size()) {
                int x = gr[t][pos];
                if(!has_found[x]) {
                    has_found[x] = 1;
                    qe.push(x);
                }
                pos++;
            }
            has_found[t] = 1;
        }
    }
    int bfs_again(int i) {
        int origin = -1;
        initial();
        queue<int> qe;
        qe.push(i);
        while(!qe.empty()) {
            int t = qe.front(), pos = 0;
            qe.pop();
            while(pos < gr[t].size()) {
                int x = gr[t][pos];
                if(!has_found[x]) {
                    depth[x] = depth[t] + 1;
                    qe.push(x);
                }
                pos++;
            }
            has_found[t] = 1;
            if(depth[t] > origin) origin = depth[t];
        }
        return origin;
    }
    
    void dfs(int i) {
        int pos = 0;
        has_found[i] = 1;
        while(pos < gr[i].size()) {
            if(has_found[gr[i][pos]]) {
                pos++;
                continue;
            }
            dfs(gr[i][pos]);
            pos++;
        }
    }

};

struct compare {
    bool operator() (edge a, edge b) {
        return a.weight > b.weight || (a.weight == b.weight && a.end < b.end);
    }
};
int main(int argc, const char * argv[]) {
    vector<edge> vec;
    int n, a, b;
    scanf("%d", &n);
    graph g(n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &a, &b);
        g.add_edge(a, b);
    }
    int p = g.is_connected();
    if (p > 1) {
        printf("Error: %d components", p);
    }
    else {
        for(int i = 1; i <= n; i++) {
            vec.push_back(edge(i, g.bfs_again(i)));
        }
        sort(vec.begin(), vec.end(), compare());
        int fin = vec[0].weight;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].weight == fin)
                printf("%d\n", vec[i].end);
    
        }
    }
    return 0;
}
