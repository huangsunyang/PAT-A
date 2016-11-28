//
//  main.cpp
//  1079
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int id;
    vector<int> next;
    int amount = 0;
    double depth = 1;
};

node shops[100003];
bool has_found[1000003];
double breadth_first_search(double rate, double price) {
    int rt = 0;
    double ret = 0.0;
    queue<int> que;
    que.push(rt);
    has_found[rt] = true;
    shops[rt].depth = price;
    while (!que.empty()) {
        rt = que.front();
        if (shops[rt].amount != 0) {
            ret += shops[rt].amount * shops[rt].depth;
        }
        que.pop();
        for (int i = 0; i < shops[rt].next.size(); i++) {
            int serial = shops[rt].next[i];
            if (!has_found[serial]) {
                que.push(serial);
                shops[serial].depth = shops[rt].depth * rate;
            }
        }
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int n;
    double price, rate;
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = 1 + rate / 100;
    for (int i = 0; i < n; i++) {
        int low_num;
        scanf("%d", &low_num);
        if (low_num == 0) {
            scanf("%d", &shops[i].amount);
        } else {
            for (int j = 0; j < low_num; j++) {
                int temp;
                scanf("%d", &temp);
                shops[i].next.push_back(temp);
            }
        }
    }
    printf("%.1lf\n", breadth_first_search(rate, price));
    return 0;
}
