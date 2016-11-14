//
//  main.cpp
//  1007
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    int * ar = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int start = -1, end = -1, sum = 0, max = 0xF0000000;
    int final_start = start, final_end = end;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (ar[i] > 0 || ar[i] + sum >= 0) {
            if(first) {
                start = i;
                first = false;
            }
            sum += ar[i];
        }
        else {
            sum = 0;
            start = i + 1;
        }
        if (sum > max) {
            max = sum;
            final_start = start;
            final_end = i;
        }
    }
    if (max <= 0) {
        max = 0xF0000000;
        for (int i = 0; i < n; i++) {
            if (ar[i] > max) {
                max = ar[i];
            }
        }
        if (max != 0) {
            printf("%d %d %d", 0, ar[0], ar[n - 1]);
        }
        else printf("0 0 0");
        return 0;
    }
    printf("%d %d %d", max, ar[final_start], ar[final_end]);
    return 0;
}
