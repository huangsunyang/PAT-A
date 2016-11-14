//
//  main.cpp
//  1115
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <queue>

struct node {
    node(int k, int l): key(k), left(NULL), right(NULL), depth(l){}
    node * left, * right;
    int key;
    int depth;
};

struct tree {
    node * head = NULL;
    void insert(int x) {
        if(head == NULL) {
            head = new node(x, 0);
            return;
        }
        node * temp = head;
        while (temp != NULL) {
            if(x <= temp->key) {
                if(temp->left == NULL) {
                    temp->left = new node(x, temp->depth + 1);
                    return;
                }
                else temp = temp->left;
            }
            else {
                if(temp->right == NULL) {
                    temp->right = new node(x, temp->depth + 1);
                    return;
                }
                else temp = temp->right;
            }
        }
    }
    
    void transversal(int &a, int &b) {
        int vec[2001];
        for (int i = 0; i < 2001; i++) {
            vec[i] = 0;
        }
        std::queue<node *> que;
        que.push(head);
        while(!que.empty()) {
            node * t = que.front();
            vec[t->depth]++;
            que.pop();
            if (t->left != NULL) {
                que.push(t->left);
            }
            if (t->right != NULL) {
                que.push(t->right);
            }
        }
        for (int i = 2000; i >= 0; i--) {
            if(vec[i] != 0) {
                a = vec[i];
                b = vec[i - 1];
                //printf("%d %d\n", i, a);
                return;
            }
        }
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    tree trees;
    int n, temp, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        trees.insert(temp);
    }
    trees.transversal(a, b);
    printf("%d + %d = %d", a, b, a + b);
    return 0;
}
