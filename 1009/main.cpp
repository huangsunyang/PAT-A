//
//  main.cpp
//  1009
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <math.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    double a[1001], b[1001], c[2001];
    for (int i = 0; i < 2001; i++) {
        c[i] = 0;
    }
    int num, exponent;
    double cofficient;
    scanf("%d", &num);
    while (num--) {
        scanf("%d %lf", &exponent, &cofficient);
        a[exponent] = cofficient;
    }
    scanf("%d", &num);
    while (num--) {
        scanf("%d %lf", &exponent, &cofficient);
        b[exponent] = cofficient;
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j ++) {
            c[i + j] += (a[i] * b[j]);
        }
    }
    int n = 2001;
    for (int i = 2000; i >= 0; i--) {
        if (fabs(c[i]) < 0.0000001) {
            n--;
        }
    }
    printf("%d", n);
    for (int i = 2000; i >= 0; i--) {
        if (fabs(c[i]) < 0.0000001) {
            continue;
        }
        printf(" %d %.1lf", i, c[i]);
    }
    return 0;
}
