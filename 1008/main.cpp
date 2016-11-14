//
//  main.cpp
//  1008
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    int * ar = new int [n + 1];
    ar[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &ar[i]);
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum += 5;
        int c = ar[i] - ar[i-1] > 0 ? 6 : -4;
        sum += c * (ar[i] - ar[i-1]);
    }
    printf("%d", sum);
    return 0;
}
