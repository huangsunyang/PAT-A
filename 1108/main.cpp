//
//  main.cpp
//  1108
//
//  Created by huangsunyang on 10/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string.h>
bool get_int(const char * s, double &p) {
    int st = 0, left = 0;
    double right = 0.0;
    if (s[0] == '-') {
        st = 1;
    }
    int i = st;
    while (s[i] != '\0' && s[i] != '.') {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            left = (left * 10) + s[i] - '0';
            if(left > 1000) return false;
        }
        i++;
    }
    if (s[i] == '\0') {
        p = (1 - 2 * st) * left;
        //printf("%lf\n", p);
        return true;
    }
    i++;
    int j = 10;
    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        } else {
            right += (s[i] - '0') * 1.0 / j;
            if(right + left > 1000) return false;
        }
        i++;
        j *= 10;
        if(j > 1000) return false;
    }
    p = (1 - 2 * st) * (left + right);
    //printf("%lf\n", p);
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, num = 0;
    double total = 0.0, p;
    char temp[30];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        if(get_int(temp, p)) {
            num++;
            total += p;
        } else {
            printf("ERROR: %s is not a legal number\n", temp);
        }
    }
    if (num == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else {
        printf("The average of %d number%s is %.2lf\n", num, num == 1 ? "" : "s", total / num);
    }
    return 0;
}
