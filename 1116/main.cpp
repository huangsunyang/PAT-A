//
//  main.cpp
//  1116
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
int find_it(int * ar, int a) {
    return ar[a] > 0 ? ar[a] - 1 : -1;
}

bool is_prime(int n) {
    if(n == 1) return false;
    if(n == 2) return true;
    int k = int(sqrt(n));
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    int n, temp, m;
    int ar[100000];
    scanf("%d", &n);
    std::vector<int> vec, has_checked;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        ar[temp] = i + 1;
        has_checked.push_back(0);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        printf("%04d: ", temp);
        int k = find_it(ar, temp);
        if (k == -1) {
            printf("Are you kidding?\n");
        } else if(has_checked[k]) {
            printf("Checked\n");
        }else if (k == 0) {
            printf("Mystery Award\n");
            has_checked[k] = 1;
        } else if(is_prime(k + 1)) {
            printf("Minion\n");
            has_checked[k] = 1;
        } else {
            printf("Chocolate\n");
            has_checked[k] = 1;
        }
    }
    return 0;
}
