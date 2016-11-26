//
//  main.cpp
//  1078
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <math.h>

bool is_prime(int n) {
    if (n == 1) {
        return false;
    }
    int end = int(sqrt(n));
    for (int i = 2; i <= end; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int * ar;

int main(int argc, const char * argv[]) {
    int n, m;
    bool first = true;
    scanf("%d %d", &n, &m);
    while (!is_prime(n)) {
        n++;
    }
    ar = new int[n]();
    for (int i = 0; i < n; i++) {
        ar[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int temp;
        scanf("%d", &temp);
        int pos = temp % n;
        if (!first) {
            putchar(' ');
        } else {
            first = false;
        }
        int k = 1, st_pos = pos;
        while (ar[pos] != 0 && k < n) {
            pos = (st_pos + k * k) % n;
            k++;
        }
        if (k <= n && ar[pos] == 0) {
            printf("%d", pos);
            ar[pos] = 1;
        } else {
            putchar('-');
        }
        
    }
    putchar('\n');
    return 0;
}
