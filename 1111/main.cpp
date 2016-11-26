//
//  main.cpp
//  1111
//
//  Created by huangsunyang on 11/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
    vector<int> adj;
    vector<int> len;
    vector<int> time;
    int cur_time = 0x7FFFFFFF;
    int cur_dis = 0x7FFFFFFF;
    int temp_time = 0x7FFFFFFF;
    int time_pre = -1;
    int dis_pre = -1;
    int depth = 0x7FFFFFFF;
};

node nodes[500];
bool has_found[500];

struct compare1 {
    bool operator()(int& a, int &b) {
        return nodes[a].cur_dis > nodes[b].cur_dis;
    }
};
struct compare2 {
    bool operator()(int& a, int& b) {
        return nodes[a].cur_time > nodes[b].cur_time;
    }
};

int main(int argc, const char * argv[]) {
    priority_queue<int, vector<int>, compare1> stacks;
    int n, m, st, ed;
    int from, to, one_way, temp_len, temp_time;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &from, &to, &one_way, &temp_len, &temp_time);
        nodes[from].adj.push_back(to);
        nodes[from].len.push_back(temp_len);
        nodes[from].time.push_back(temp_time);
        if (!one_way) {
            nodes[to].adj.push_back(from);
            nodes[to].len.push_back(temp_len);
            nodes[to].time.push_back(temp_time);
        }
    }
    scanf("%d %d", &st, &ed);
    nodes[st].cur_dis = 0;
    nodes[st].cur_time = 0;
    nodes[st].temp_time = 0;
    nodes[st].depth = 0;
    stacks.push(st);
    int cpt;
    for (int i = 0; i < n; i++) {
        has_found[i] = false;
    }
    for (int i = 0; i < n; i++) {
        while (has_found[stacks.top()]) {
            stacks.pop();
        }
        cpt = stacks.top();
        has_found[cpt] = 1;
        stacks.pop();
        for (int j = 0; j < nodes[cpt].adj.size(); j++) {
            int next = nodes[cpt].adj[j];
            if (has_found[next]) {
                continue;
            }
            if (nodes[next].cur_dis > nodes[cpt].cur_dis + nodes[cpt].len[j]) {
                nodes[next].cur_dis = nodes[cpt].cur_dis + nodes[cpt].len[j];
                nodes[next].dis_pre = cpt;
                nodes[next].temp_time = nodes[cpt].temp_time + nodes[cpt].time[j];
                stacks.push(next);
            } else if (nodes[next].cur_dis == nodes[cpt].cur_dis + nodes[cpt].len[j]) {
                if (nodes[next].temp_time > nodes[cpt].temp_time + nodes[cpt].time[j]) {
                    nodes[next].dis_pre = cpt;
                    nodes[next].temp_time = nodes[cpt].temp_time + nodes[cpt].time[j];
                    stacks.push(next);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        has_found[i] = false;
    }
    priority_queue<int, vector<int>, compare2> stacks2;
    stacks2.push(st);
    for (int i = 0; i < n; i++) {
        while (has_found[stacks2.top()]) {
            stacks2.pop();
        }
        cpt = stacks2.top();
        has_found[cpt] = 1;
        stacks2.pop();
        for (int j = 0; j < nodes[cpt].adj.size(); j++) {
            int next = nodes[cpt].adj[j];
            if (has_found[next]) {
                continue;
            }
            if (nodes[next].cur_time > nodes[cpt].cur_time + nodes[cpt].time[j]) {
                nodes[next].cur_time = nodes[cpt].cur_time + nodes[cpt].time[j];
                nodes[next].time_pre = cpt;
                nodes[next].depth = nodes[cpt].depth + 1;
                stacks2.push(next);
            } else if (nodes[next].cur_time == nodes[cpt].cur_time + nodes[cpt].time[j]) {
                if (nodes[next].depth > nodes[cpt].depth + 1) {
                    nodes[next].time_pre = cpt;
                    nodes[next].depth = nodes[cpt].depth + 1;
                    stacks2.push(next);
                }
            }
        }
    }
    vector<int> times;
    vector<int> distances;
    int temp = ed;
    while (temp != -1) {
        distances.push_back(temp);
        temp = nodes[temp].dis_pre;
    }
    temp = ed;
    while (temp != -1) {
        times.push_back(temp);
        temp = nodes[temp].time_pre;
    }
    printf("Distance = %d", nodes[ed].cur_dis);
    if (equal(times.begin(), times.end(), distances.begin())) {
        printf("; ");
    } else {
        printf(": %d", distances.back());
        for (int i = int(distances.size()) - 2; i >= 0; i--) {
            printf(" -> %d", distances[i]);
        }
        putchar('\n');
    }
    printf("Time = %d: %d", nodes[ed].cur_time, times.back());
    for (int i = int(times.size()) - 2; i >= 0; i--) {
        printf(" -> %d", times[i]);
    }
    putchar('\n');
    return 0;
}
