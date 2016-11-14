//
//  main.cpp
//  1011
//
//  Created by huangsunyang on 9/8/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <math.h>
double max(double a, double b, double c, char * answer) {
    if (a > b && a > c) {
        *answer = 'W';
        return a;
    } else if(b > a && b > c) {
        *answer = 'T';
        return b;
    } else {
        *answer = 'L';
        return c;
    }
}
double get_right(double a) {
    a *= 100;
    if (a < double(int(a) + 0.499999999)) {
        return a / 100;
    }
    return (a + 1)/100;
}

int main(int argc, const char * argv[]) {
    double x, y, z, sum = 1.0;
    char answer;
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &x);
        scanf("%lf", &y);
        scanf("%lf", &z);
        sum *= max(x, y, z, &answer);
        printf("%c ", answer);
    }
    sum = (sum * 0.65 - 1) * 2;
    printf("%.2lf", sum);
    return 0;
}
