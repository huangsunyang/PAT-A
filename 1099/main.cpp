//
//  main.cpp
//  1099
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int father;
    int left;
    int right;
    int key;
};
node nodes[100];

int find_root(int n) {
    for (int i = 0; i < n; i++) {
        if (nodes[i].father == -1) {
            return i;
        }
    }
    return -1;
}

void mid_order_transversal(int rt, vector<int> & vec) {
    assert(!vec.empty());
    if (nodes[rt].left != -1) {
        mid_order_transversal(nodes[rt].left, vec);
    }
    nodes[rt].key = vec.back();
    vec.pop_back();
    if (nodes[rt].right != -1) {
        mid_order_transversal(nodes[rt].right, vec);
    }
}

void level_transversal(int rt, vector<int> & vec) {
    queue<int> que;
    que.push(rt);
    while (!que.empty()) {
        int t = que.front();
        vec.push_back(nodes[t].key);
        que.pop();
        if (nodes[t].left != -1) {
            que.push(nodes[t].left);
        }
        if (nodes[t].right != -1) {
            que.push(nodes[t].right);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, t;
    std::vector<int> vec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        nodes[i].father = -1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
        if (nodes[i].left != -1) {
            nodes[nodes[i].left].father = i;
        }
        if (nodes[i].right != -1) {
            nodes[nodes[i].right].father = i;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        vec.push_back(t);
    }
    sort(vec.rbegin(), vec.rend());
    int root = find_root(n);
    assert(root != -1);
    mid_order_transversal(root, vec);
    level_transversal(root, vec);
    printf("%d", vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        printf(" %d", vec[i]);
    }
    putchar('\n');
    return 0;
}
