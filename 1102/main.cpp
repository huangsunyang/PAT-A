//
//  main.cpp
//  1102
//
//  Created by huangsunyang on 11/8/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;

struct node {
    node(int a, int b):left(a), right(b){}
    int left, right;
};

void transversal(vector<node> tree, int root) {
    printf("%d", root);
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        int rt = que.front();
        que.pop();
        if (tree[rt].left != -1) {
            printf(" %d",tree[rt].left);
            que.push(tree[rt].left);
        }
        if (tree[rt].right != -1) {
            printf(" %d",tree[rt].right);
            que.push(tree[rt].right);
        }
    }
}

void inorder(vector<node> tree, int root) {
    stack<int> que;
    int rt = root, flag = 1;
    //当栈不为空
    while (!que.empty() || rt != -1) {
        //先把左侧节点全部进栈
        while (rt != -1) {
            que.push(rt);
            rt = tree[rt].left;
        }
        if(!que.empty()) {
            //弹出栈顶(左侧元素)
            rt = que.top();
            if(flag == 1) {
                printf("%d", rt);
                flag = 0;
            }
            else printf(" %d", rt);
            que.pop();
            rt = tree[rt].right;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, t1, t2, root = 0;
    char temp1[20], temp2[20];
    scanf("%d", &n);
    vector<node> tree;
    int sum[100];
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
        scanf("%s %s", temp1, temp2);
        if (temp1[0] == '-') {
            t1 = -1;
        } else {
            t1 = int(strtol(temp1, NULL, 10));
            sum[t1]++;
        }
        if (temp2[0] == '-') {
            t2 = -1;
        } else {
            t2 = int(strtol(temp2, NULL, 10));
            sum[t2]++;
        }
        tree.push_back(node(t2, t1));
    }
    for (int i = 0; i < n; i++) {
        if (sum[i] == 0) {
            root = i;
            break;
        }
    }
    transversal(tree, root);
    putchar('\n');
    inorder(tree, root);
    putchar('\n');
    return 0;
}
