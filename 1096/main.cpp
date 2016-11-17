//
//  main.cpp
//  1096
//
//  Created by huangsunyang on 11/17/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

void find_min_factor(int n, vector<int> & vec) {
    int end = int(sqrt(n)) + 1;
    int start;
    for (start = 2; start < end; start ++) {
        if (n % start == 0) {
            vec.push_back(start);
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    vector<int> vec;
    scanf("%d", &n);
    find_min_factor(n, vec);
    size_t end = vec.size() - 1;
    for (int i = int(end); i >= 0; i--) {
        if (vec[i] != n / vec[i]) {
            vec.push_back(n / vec[i]);
        }
    }
    vec.push_back(n);
//    for_each(vec.begin(), vec.end(), [](int n) {printf("%d ", n); });
//    putchar('\n');
    int max = 1, final_start = 0;
    int cur_max = 1, cur_start = 0, sum = 1;
    for (int i = 0; i < vec.size() - 1; i++) {
        int j = i;
        cur_start = j;
        cur_max = 1;
        sum = vec[j];
        while (j < vec.size() - 1 && vec[j + 1] == vec[j] + 1) {
            sum *= vec[j + 1];
            if(sum > n || n % sum != 0) break;
            cur_max++;
            j++;
        }
        if (cur_max > max) {
            final_start = cur_start;
            max = cur_max;
        }
    }
    
    printf("%d\n%d", max, vec[final_start]);
    final_start++, max--;
    for (int i = 0; i < max; i++, final_start++) {
        printf("*%d", vec[final_start]);
    }
    putchar('\n');
    return 0;
}
