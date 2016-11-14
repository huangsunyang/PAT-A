//
//  main.cpp
//  1117
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, temp;
    int array[200000];
    for (int i = 0; i < 200000; i++) {
        array[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if(temp > n) array[n + 1]++;
        else array[temp]++;
    }
    for (int i = n + 1; i > 0; i--) {
        array[i - 1] += array[i];
    }
    for (int i = n + 1; i >= 1; i--) {
        if (array[i] >= i - 1) {
            printf("%d\n", i - 1);
            break;
        }
    }
    return 0;
}
