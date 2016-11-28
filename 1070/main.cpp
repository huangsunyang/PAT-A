//
//  main.cpp
//  1070
//
//  Created by huangsunyang on 11/27/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct moon {
    double storage;
    double price;
    double per_price;
};

bool compare(const moon &a, const moon &b) {
    return a.price * b.storage > b.price * a.storage;
}

int main(int argc, const char * argv[]) {
    int n;
    double total;
    scanf("%d %lf", &n, &total);
    vector<moon> vec(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i].storage);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i].price);
        vec[i].per_price = vec[i].price / vec[i].storage;
    }
    sort(vec.begin(), vec.end(), compare);
    double money = 0;
    for (int i = 0; i < vec.size() && total > 0; i++) {
        if (total > vec[i].storage) {
            total -= vec[i].storage;
            money += vec[i].storage * vec[i].per_price;
        } else {
            money += total * vec[i].per_price;
            total = 0;
            break;
        }
    }
    printf("%.2lf\n", money);
    return 0;
}
