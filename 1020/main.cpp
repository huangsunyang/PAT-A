//
//  main.cpp
//  1020
//
//  Created by huangsunyang on 9/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int ar[100], br[100];
int c[100000];
struct node {
    int num = -1;
    node * left = NULL;
    node * right = NULL;
};
class tree {
    node * root;
};
void find_tree(int * a, int st_a, int ed_a, int * b, int st_b, int ed_b, node * & root) {
    if(st_a > ed_a || st_b > ed_b) return;
    root = new node();
    root->num = a[ed_a];
    int pos_b = br[a[ed_a]];    //a中末尾元素在b中的位置
    int l_num = pos_b - st_b;
    find_tree(a, st_a, st_a + l_num - 1, b, st_b, pos_b - 1, root->left);
    find_tree(a, st_a + l_num, ed_a - 1, b, pos_b + 1, ed_b, root->right);
    return;
}


void print(node * root) {
    queue<node *> que;
    if (root == NULL) {
        return;
    }
    printf("%d", root->num);
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        node * n = que.front();
        if (n != NULL) {
            printf(" %d", n->num);
            que.push(n->left);
            que.push(n->right);
        }
        que.pop();
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int *a, *b;
    node * root;
    scanf("%d", &n);
    a = new int[n];
    b = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        ar[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        br[b[i]] = i;
    }
    find_tree(a, 0, n-1, b, 0, n-1, root);
    print(root);
    return 0;
}
