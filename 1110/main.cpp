//
//  main.cpp
//  1110
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <queue>
struct node {
    int left, right;
};
int find_root(int * answer, int n);
int s_to_int(char * ch) {
    int sum = 0;
    while (*ch != '\0') {
        sum = sum * 10 + *ch++ - '0';
    }
    return sum;
}

bool is_binary(const node * ar, int * answer, int n) {
    for (int i = 0; i < n; i++) {
        answer[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if(ar[i].left > -1) answer[ar[i].left] = i;
        if(ar[i].right > -1) answer[ar[i].right] = i;
    }
    int br[40];
    std::queue<int> que;
    int a = find_root(answer, n);
    que.push(a);
    br[a] = 0;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        if(ar[t].left != -1) {
            que.push(ar[t].left);
            br[ar[t].left] = 2 * br[t] + 1;
            if (2 * br[t] + 1 >= n) {
                return false;
            }
        }
        if(ar[t].right != -1) {
            que.push(ar[t].right);
            br[ar[t].right] = 2 * br[t] + 2;
            if (2 * br[t] + 2 >= n) {
                return false;
            }
        }
    }
    return true;
}

int find_root(int * answer, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (answer[i] != -1) {
            break;
        }
    }
    while (answer[i] != -1) {
        i = answer[i];
    }
    return i;
}

int find_last(int * answer, const node * ar, int n) {
    int br[40];
    std::queue<int> que;
    int a = find_root(answer, n);
    que.push(a);
    int count = 0;
    while (!que.empty()) {
        int t = que.front();
        if(!que.empty()) que.pop();
        br[count++] = t;
        if(ar[t].left != -1) {
            que.push(ar[t].left);
        }
        if(ar[t].right != -1) {
            que.push(ar[t].right);
        }
    }
    return br[n-1];
}


int main(int argc, const char * argv[]) {
    node ar[30];
    char t1[5], t2[5];
    int n;
    int answer[30];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%s %s", t1, t2);
        if (t1[0] == '-') ar[i].left = -1;
        else ar[i].left = s_to_int(t1);
        if (t2[0] == '-') ar[i].right = -1;
        else ar[i].right = s_to_int(t2);
    }
    bool tag = is_binary(ar, answer, n);
    int a;
    if(tag) a = find_last(answer, ar, n);
    else a = find_root(answer, n);
    printf("%s %d\n", tag ? "YES" : "NO", a);
    return 0;
}
