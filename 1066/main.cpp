//
//  main.cpp
//  1066
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
struct node {
    node(int a): key(a){}
    node * left = NULL;
    node * right = NULL;
    int key;
    int height = 0;
};

struct tree {
    node * root = NULL;
    void left_rotate(node * ptr) {
        node * temp = ptr;
    }
    
    void insert(int key) {
        if (root == NULL) {
            root = new node(key);
            return;
        }
        node * ptr = root;
        while (ptr != NULL) {
            if (ptr->key > key) {
                if(ptr->left != NULL)
                    ptr = ptr->left;
                else {
                    ptr->left = new node(key);
                    ptr = ptr->left;
                }
            } else {
                if(ptr->right != NULL)
                    ptr = ptr->right;
                else {
                    ptr->right = new node(key);
                    ptr = ptr->right;
                }
            }
        }
        while(ptr != root) {
            ptr = ptr->parent;
            int l, r;
            if (ptr->left == NULL) {
                l = -1;
            } else l = ptr->left->height;
            if (ptr->right == NULL) {
                r = -1;
            } else r = ptr->right->height;
            ptr->height = std::max(l, r) + 1;
            if (l - r > 1) {
                node * temp = ptr;
                if (ptr->parent != NULL) {
                    ptr->parent = ptr->left;
                }
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    return 0;
}
