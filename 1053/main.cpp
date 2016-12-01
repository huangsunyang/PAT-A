//
//  main.cpp
//  1053
//
//  Created by huangsunyang on 12/1/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct node {
    int key;
    int sum = 0;
    int pre;
    vector<int> next;
};

node vec[100];
int target;
void print_path(int n);

void breath_first_search(int root = 0) {
    queue<int> que;
    que.push(root);
    vec[root].sum = vec[root].key;
    vec[root].pre = -1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        if (vec[t].next.empty() && vec[t].sum == target) {
            print_path(t);
        }
        for (int i = 0; i < vec[t].next.size(); i++) {
            int next_node = vec[t].next[i];
            que.push(next_node);
            vec[next_node].sum = vec[t].sum + vec[next_node].key;
            vec[next_node].pre = t;
        }
    }
    //printf("breath_first end\n");
}

void depth_first_search(int root = 0) {
    stack<int> st;
    st.push(root);
    vec[root].sum = vec[root].key;
    vec[root].pre = -1;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        while (!vec[top].next.empty()) {
            for (int i = 0; i < vec[top].next.size() - 1; i++) {
                int tn = vec[top].next[i];
                st.push(tn);
                vec[tn].sum = vec[top].sum + vec[tn].key;
                vec[tn].pre = top;
            }
            int next = vec[top].next.back();
            vec[next].sum = vec[top].sum + vec[next].key;
            vec[next].pre = top;
            top = next;
        }
        if (vec[top].sum == target) {
            print_path(top);
        }
    }
}


void print_path(int n) {
    vector<int> temp;
    while (n != -1) {
        temp.push_back(vec[n].key);
        n = vec[n].pre;
    }
    for (vector<int>::reverse_iterator i = temp.rbegin(); i != temp.rend(); i++) {
        printf("%d%c", *i, i == temp.rend() - 1 ? '\n' : ' ');
    }
}

bool compare(int a, int &b) {
    return vec[a].key < vec[b].key;
}

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d %d", &n, &m, &target);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i].key);
    }
    for (int i = 0; i < m; i++) {
        int id, temp_next, num;
        scanf("%d %d", &id, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &temp_next);
            vec[id].next.push_back(temp_next);
        }
        sort(vec[id].next.begin(), vec[id].next.end(), compare);
    }
    depth_first_search();
    return 0;
}
