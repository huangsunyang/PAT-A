//
//  main.cpp
//  1094
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct person {
    int parent;
    vector<int> children;
    int depth;
};

person famliy[101];

void breadth_first_search() {
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < famliy[cur].children.size(); i++) {
            int k = famliy[cur].children[i];
            famliy[k].depth = famliy[cur].depth + 1;
            que.push(k);
        }
    }
}

int main(int argc, const char * argv[]) {
    int n, m;
    int dep[101];
    for (int i = 0; i < 101; i++) {
        dep[i] = 0;
    }
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int id, child_num;
        scanf("%d %d", &id, &child_num);
        for (int j = 0; j < child_num; j++) {
            int temp;
            scanf("%d", &temp);
            famliy[id].children.push_back(temp);
            famliy[temp].parent = id;
        }
    }
    famliy[1].depth = 0;
    breadth_first_search();
    for (int i = 1; i <= n; i++) {
        dep[famliy[i].depth]++;
    }
    int max = -1, num = -1;
    for (int i = 0; i < n; i++) {
        if (dep[i] >max) {
            max = dep[i];
            num = i;
        }
    }
    printf("%d %d\n",max, num + 1);
    return 0;
}












