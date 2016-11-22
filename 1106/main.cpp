//
//  main.cpp
//  1106
//
//  Created by huangsunyang on 11/21/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>
int retailer[100000];
int depth[100000];
bool is_retailer[100000];
double rates[100000];

int cal_dep(int a) {
    if (depth[a] != -1) {
        return depth[a];
    }
    depth[a] = cal_dep(retailer[a]) + 1;
    return depth[a];
}



int main(int argc, const char * argv[]) {
    int n, m, t;
    double price, rate;
    retailer[0] = -1;
    depth[0] = 0;
    is_retailer[0] = false;
    scanf("%d %lf %lf", &n, &price, &rate);
    
    for (int i = 1; i < n; i++) {
        depth[i] = -1;
        is_retailer[i] = false;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        if (m == 0) {
            is_retailer[i] = true;
        }
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            retailer[t] = i;
            if (depth[i] != -1) {
                depth[t] = depth[i] + 1;
            }
        }
    }
    int min = 0x7FFFFFFF, num = 0;
    for (int i = 0; i < n; i++) {
        if (is_retailer[i]) {
            int d = cal_dep(i);
            if (d == min) {
                num++;
            } else if (d < min) {
                min = d;
                num = 1;
            }
        }
    }
    rate = rate / 100 + 1.;
    rates[0] = 1;
    for (int i = 1; i < n; i++) {
        rates[i] = rates[i - 1] * rate;
    }
    printf("%.4lf %d\n", price * rates[min], num);
    return 0;
}
