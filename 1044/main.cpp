//
//  main.cpp
//  1044
//
//  Created by huangsunyang on 12/5/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//
//剪枝优化
#include <iostream>
#include <vector>
using namespace std;

struct answer {
    answer(){}
    answer(int x, int y): st(x), ed(y){}
    int st, ed;
};

int vec[100004];
answer answ[100000];

int main(int argc, const char * argv[]) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<answer> ans;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &vec[i]);
    }
    int idx = 0;
    int diff_min = 0x7FFFFFFF;
    int temp_sum = 0;
    for (int i = 1, j = 1; j <= n + 1;) {
        if (temp_sum < m) {
            temp_sum += vec[j];
            j++;
            continue;
        } else if (temp_sum - m == diff_min) {
            answ[idx++] = answer(i, j);
        } else if (temp_sum - m < diff_min) {
            idx = 0;
            diff_min = temp_sum - m;
            answ[idx++] = answer(i, j);
        }
        temp_sum -= vec[i];
        i++;
    }
    for (int i = 0; i < idx; i++) {
        printf("%d-%d\n", answ[i].st, answ[i].ed - 1);
    }
    return 0;
}
