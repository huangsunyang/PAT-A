//
//  main.cpp
//  1004
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
int char_to_int(char a, char b) {
    return (a - '0') * 10 + (b - '0');
}
int my_get_integer() {
    char a, b;
    while ((a = getchar()) > '9' || a < '0') {
    }
    b = getchar();
    return char_to_int(a, b);
}
//计算每一个节点的层数
int count(int i, int * ar, int * br, bool * cr, bool * dr) {
    if (ar[i] == -1) {
        cr[i] = true;
        br[i] = 1;
        return 1;
    }
    else if (cr[i]) return br[i];
    else {
        dr[ar[i]] = true;
        cr[i] = true;
        br[i] = count(ar[i], ar, br, cr, dr) + 1;
        return br[i];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int nodes_num, non_leaf_num;
    scanf("%d %d", &nodes_num, &non_leaf_num);
    //建树，数组内元素保存的是父节点，从1开始
    int * tree = new int[nodes_num + 1], n;
    for (int i = 1; i <= nodes_num; i++) {
        tree[i] = -1;
    }
    for (int i = 0; i < non_leaf_num; i++) {
        int father = my_get_integer();
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int child = my_get_integer();
            tree[child] = father;
        }
    }
    //建立完毕
    bool * has_count = new bool[nodes_num + 1];     //保存是否已经数过层数
    bool * has_child = new bool[nodes_num + 1];     //保存是否有子女
    int * floor_num = new int[nodes_num + 1];       //保存该节点所在的层数
    int * final = new int[nodes_num + 1];           //保存第i层无子女的个数
    for (int i = 0; i <= nodes_num; i++) {
        has_count[i] = false;
        has_child[i] = false;
        final[i] = 0;
    }
    //计算每个节点的层数
    for (int i = 1; i < nodes_num + 1; i++) {
        if (has_count[i]) {
            continue;
        }
        count(i, tree, floor_num, has_count, has_child);    //计算层数
    }
    //计算完毕, has_child保存各个节点是否有子女的信息
    int max = 0;
    for (int i = 1; i < nodes_num + 1; i++) {
        if (!has_child[i]) {
            max = max > floor_num[i] ? max : floor_num[i];
            final[floor_num[i]]++;
        }
    }
    printf("%d", final[1]);
    for (int i = 2; i <= max; i++) {
        printf(" %d", final[i]);
    }
    return 0;
}
