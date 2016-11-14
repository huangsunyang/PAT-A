//
//  main.cpp
//  1118
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int find_first_bird(int * birds, int k) {
    if (birds[k] != k) {
        birds[k] = find_first_bird(birds, birds[k]);
    }
    return birds[k];
}

void link(int * birds, int a, int b) {
    int p = find_first_bird(birds, a);
    int q = find_first_bird(birds, b);
    birds[p] = q;
}

int main(int argc, const char * argv[]) {
    int birds[20003];
    int trees[20003];
    vector<int> vec;
    int n, m, l, temp, temp1, tree_num = 0, max_birds = 0;
    int a, b;
    //初始化
    for (int i = 0; i < 20003; i++) {
        trees[i] = 0;
        birds[i] = -1;
    }
    scanf("%d", &n);    //图片数量
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);    //图片中鸟的数量
        for(int j = 0; j < m; j++) {
            scanf("%d", &temp);
            vec.push_back(temp);    //先保存起来再说
        }
        temp1 = vec[0];
        for (int j = 0; j < m; j++) {
            if (birds[vec[j]] != -1) {
                temp1 = birds[vec[j]];
                break;                  //找到一个有父节点的，找不到就任意找一个即可
            }
        }
        for (int j = 0; j < m; j++) {
            if(birds[vec[j]] == -1)
                birds[vec[j]] = temp1;      //原来没有指过，那么指向一只鸟王
            else {                          //原来已经在另一个集合中
                link(birds, vec[j], vec[0]);
            }
        }
        vec.clear();
    }
    for (int i = 1; i < 20003; i++) {
        if (birds[i] != -1) {
            int k = find_first_bird(birds, i);      //找到每一只鸟的鸟王
            trees[k]++;                             //一只鸟王代表一棵树。这棵树上的鸟的数量加1
        } else  {
            max_birds = i - 1;                      //说明编号到此结束了
            break;
        }
    }
    for (int i = 1; i <= max_birds; i++) {
        if(trees[i] != 0) {                     //有多少棵树上有鸟，代表就有多少棵树
            tree_num++;
        }
    }
    printf("%d %d\n", tree_num, max_birds);
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d %d", &a, &b);
        printf("%s", birds[a] == birds[b]  ? "Yes\n" : "No\n"); //鸟王一样说明在一棵树上
    }
    return 0;
}
