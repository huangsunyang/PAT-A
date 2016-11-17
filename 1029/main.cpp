//
//  main.cpp
//  1029
//
//  Created by huangsunyang on 11/17/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    long temp = -1;
    vector<long> vec_1, vec_2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &temp);
        vec_1.push_back(temp);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &temp);
        vec_2.push_back(temp);
    }
    long mid = (vec_1.size() + vec_2.size() - 1) / 2;
    long long_max = std::max(vec_1.back(), vec_2.back()) + 1l;
    vec_1.push_back(long_max);
    vec_2.push_back(long_max);
    int i, j, k;
    for (i = 0, j = 0, k = 0; i <= mid && j < vec_1.size() && k < vec_2.size(); i++) {
        if (vec_1[j] < vec_2[k]) {
            temp = vec_1[j++];
        } else {
            temp = vec_2[k++];
        }
    }
    printf("%ld\n", temp);
    return 0;
}
