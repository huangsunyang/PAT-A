//
//  main.cpp
//  1001
//
//  Created by huangsunyang on 8/29/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    char c[15];
    char d[30];
    bool is_negaive = false;
    scanf("%d %d", &a, &b);
    int e = a + b;
    if (!e) putchar('0');
    if (e < 0) {
        is_negaive = true;
        e *= -1;
    }
    int i;
    for (i = 0; e != 0; i++) {
        int rest = e % 10;
        e /= 10;
        c[i] = rest + '0';
    }
    int k , j;
    for (j = 0, k = 0; j < i; j++, k++) {
        d[k] = c[j];
        if (k != 0 && j % 3 == 2 && j != i - 1) {
            d[++k] = ',';
        }
    }
    if (is_negaive) {
        putchar('-');
    }
    for (int i = k - 1; i > -1; i--) {
        putchar(d[i]);
    }
    return 0;
}
