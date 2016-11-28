//
//  main.cpp
//  1072
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <math.h>
#define INT_MAX 0x7FFFFFFF
using namespace std;
int n, m, k, ds;
int * shortest;
bool * has_found;
int ** dis;

//将字符串转为数字
long to_int(char * s) {
    if (s[0] != 'G') {
        return strtol(s, NULL, 10);
    } else {
        return n + strtol(s + 1, NULL, 10);
    }
}

struct compare {
    bool operator() (const int a, const int b) {
        return shortest[a] > shortest[b];
    }
};

void dijkstra(int st, vector<int> & vec, vector<int> & vec2) {
    priority_queue<int, vector<int>, compare> que;
    for (int i = 1; i < n + m + 1; i++) {   //初始化
        shortest[i] = INT_MAX;
        has_found[i] = false;
    }
    int c = st;
    shortest[st] = 0;
    que.push(st);
    //找到到所有点的最短路径
    for (int k = 0; k < m + n && !que.empty(); k++) {
        while (has_found[que.top()]) {
            que.pop();
        }
        st = que.top();
        has_found[st] = true;
        que.pop();
        for (int i = 1; i < n + m + 1; i++) {
            if (has_found[i] || dis[st][i] == INT_MAX) {
                continue;
            }
            if (shortest[i] > shortest[st] + dis[st][i]) {
                shortest[i] = shortest[st] + dis[st][i];
            }
            que.push(i);
        }
    }
    int num = 0, min = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (shortest[i] > ds) {
            return;
        } else {
            num += shortest[i];
            if (shortest[i] < min) {
                min = shortest[i];
            }
        }
    }
    vec[c] = num;
    vec2[c] = min;
}

void print(double a) {
    int d = round(a * 10);
    printf("%.1lf\n", d / 10.0);
}

int main(int argc, const char * argv[]) {
    scanf("%d %d %d %d",&n, &m, &k, &ds);
    vector<int> ans(n + m + 1, -1);
    vector<int> sh(n + m + 1, 0x7FFFFFFF);
    shortest = new int[n + m + 1];
    has_found = new bool[n + m + 1];
    char s1[10], s2[10];
    int d_temp;
    dis = new int* [n + m + 1]();
    for (int i = 0; i < n + m + 1; i++) {
        dis[i] = new int[n + m + 1]();
        for (int j = 0; j < n + m + 1; j++) {
            dis[i][j] = INT_MAX;
        }
        dis[i][i] = 0;
    }
    for (int i = 0; i < k; i++) {
        scanf("%s %s %d", s1, s2, &d_temp);
        long a = to_int(s1), b = to_int(s2);
        if (a == b) continue;
        dis[a][b] = dis[b][a] = std::min(dis[a][b], d_temp);
        //printf("%d %d %d\n", a, b, d_temp);
    }
    for (int i = n + 1; i < n + m + 1; i++) {
        dijkstra(i, ans, sh);
    }
    if (find_if(ans.begin() + n + 1, ans.end(), [](int i){return i > 0;}) == ans.end()) {
        printf("No Solution\n");
    } else {
        double max_dis = -1, min_aver = INT_MAX;
        int tar = 0;
        for (int i = n + 1; i < m + n + 1; i++) {
            if (ans[i] == -1) {
                continue;
            }
            if (sh[i] > max_dis) {
                max_dis = sh[i];
                min_aver = ans[i];
                tar = i;
            } else if(sh[i] == max_dis) {
                if (min_aver > ans[i]) {
                    min_aver = ans[i];
                    tar = i;
                }
            }
        }
        printf("G%d\n", tar - n);
        printf("%.1lf ", max_dis);
        print(min_aver / n);
    }
    return 0;
}
