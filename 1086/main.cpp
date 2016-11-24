//
//  main.cpp
//  1086
//
//  Created by huangsunyang on 11/24/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node {
    node(): key(-1), left(NULL), right(NULL), parent(NULL){}
    node(int a):key(a),left(NULL),right(NULL), parent(NULL){}
    int key;
    node * left;
    node * right;
    node * parent;
};

struct tree {
    node * root;
    
};

void transversal(node * rt, vector<int> & vec) {
    if (rt->left && rt->left->key != -1) {
        transversal(rt->left, vec);
    }
    if (rt->right && rt->right->key != -1) {
        transversal(rt->right, vec);
    }
    vec.push_back(rt->key);
}


int main(int argc, const char * argv[]) {
    int n;
    stack<node *> st;
    vector<int> vec;
    scanf("%d", &n);
    char ins[6];
    node * rt = new node();
    node * root = rt;
    for (int i = 0; i < 2 * n; i++) {
        scanf("%s", ins);
        if (ins[1] == 'u') {
            scanf("%d", &rt->key);
                rt->left = new node();
                st.push(rt);
                rt = rt->left;
        } else {
            st.top()->right = new node();
            rt = st.top()->right;
            st.pop();
        }
    }
    transversal(root, vec);
    printf("%d", vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        printf(" %d", vec[i]);
    }
    putchar('\n');
    return 0;
}
