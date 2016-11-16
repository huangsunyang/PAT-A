//
//  main.cpp
//  1103
//
//  Created by huangsunyang on 11/16/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int answer[401][401];
int last[401][401];
int max_sum[401][401];

void print(int n, int k, int base, vector<int> vec) {
    printf("%d = %d^%d", n, last[n][k], base);
    n -= vec[last[n][k]];
    k--;
    while (n > 0 && k > 0 && last[n] > 0) {
        printf(" + %d^%d", last[n][k], base);
        n -= vec[last[n][k]];
        k--;
    }
    putchar('\n');
}

int main(int argc, const char * argv[]) {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    vector<int> vec, ans;
    for (int i = 0; i < 401; i++) {
        for (int j = 0; j < 401; j++) {
            answer[i][j] = -1;
            last[i][j] = 0;
            max_sum[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        int k1 = int(pow(i, p));
        if (k1 > n) {
            break;
        }
        vec.push_back(k1);
    }
    //for_each(vec.begin(), vec.end(), [](int n) {printf("%d ", n);} );
    //putchar('\n');
    for (int i = 1; i < vec.size(); i++) {
        answer[vec[i]][1] = 1;
        last[vec[i]][1] = i;
        max_sum[vec[i]][1] = i;
    }
    
    for (int j = 1; j < n + 1; j++) {
        for (int v = 1; v < vec.size() && vec[v] + j < n + 1; v++) {
            for (int t = 1; t < k; t++) {       //t代表几个数加起来和为i、j
                if (answer[j][t] == -1) {       //用t个数加起来等于j
                    continue;
                }
                if (answer[vec[v] + j][t + 1] == -1) {
                    answer[vec[v] + j][t + 1] = 1;
                    max_sum[vec[v] + j][t + 1] = max_sum[j][t] + v;
                    last[vec[v] + j][t + 1] = v;
                } else {
                    if (max_sum[vec[v] + j][t + 1] < max_sum[j][t] + v ||
                        (max_sum[vec[v] + j][t + 1] == max_sum[j][t] + v &&
                         max_sum[vec[v] + j][t + 1] < v))
                    {
                        max_sum[vec[v] + j][t + 1] = max_sum[j][t] + v;
                        last[vec[v] + j][t + 1] = v;
                    }
                }
            }
        }
    }
    if(answer[n][k] == 1) {
        print(n, k, p, vec);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
