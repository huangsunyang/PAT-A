//
//  main.cpp
//  1076
//
//  Created by huangsunyang on 11/27/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool has_found[10001];
int depth[10001];
int n, l;

int breadth_search(vector<vector<int> > &vec, int root) {
    for (int i = 1; i <= n; i++) {
        has_found[i] = false;
        depth[i] = 0;
    }
    queue<int> que;
    int ret = 0;
    que.push(root);
    has_found[root] = true;
    depth[root] = 0;
    int cpt = root;
    while (depth[cpt] < l && !que.empty()) {
        cpt = que.front();
        if (depth[cpt] >= l) break;
        que.pop();
        for (int j = 0; j < vec[cpt].size(); j++) {
            if (!has_found[vec[cpt][j]]) {
                que.push(vec[cpt][j]);
                depth[vec[cpt][j]] = depth[cpt] + 1;
                has_found[vec[cpt][j]] = true;
                ret++;
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &l);
    vector<vector<int> > vec(n + 1);
    for (int i = 1; i <= n; i++) {
        int temp_n, temp;
        scanf("%d", &temp_n);
        for (int j = 0; j < temp_n; j++) {
            scanf("%d", &temp);
            vec[temp].push_back(i);
        }
    }
    int k, query;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &query);
        printf("%d\n", breadth_search(vec, query));
    }
    return 0;
}
