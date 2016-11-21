//
//  main.cpp
//  1065
//
//  Created by huangsunyang on 11/20/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    long long a, b, c;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        //printf("%lld %lld %lld\n", a, b, a + b);
        long long k = a + b;
        if (a > 0 && b > 0 && k < 0) {
            printf("Case #%d: true\n", i);
        } else if (a < 0 && b < 0 && k >= 0) {
            printf("Case #%d: false\n", i);
        } else {
            printf("Case #%d: %s\n", i, (a + b > c ? "true" : "false"));
        }
    }
    return 0;
}
