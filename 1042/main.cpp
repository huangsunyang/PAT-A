//
//  main.cpp
//  1042
//
//  Created by huangsunyang on 11/20/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void print(int i) {
    if (i == 53) {
        printf("J1");
    } else if(i == 54) {
        printf("J2");
    }
    else {
        switch ((i - 1) / 13) {
            case 0: putchar('S'); break;
            case 1: putchar('H'); break;
            case 2: putchar('C'); break;
            case 3: putchar('D'); break;
            default: break;
        }
        printf("%d", (i - 1) % 13 + 1);
    }
}

int main(int argc, const char * argv[]) {
    int origin[55];
    int after[55];
    int change[55];
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 55; i++) {
        scanf("%d", &change[i]);
        origin[i] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 55; j++) {
            after[change[j]] = origin[j];
        }
        for (int j = 1; j < 55; j++) {
            origin[j] = after[j];
        }
    }
    print(origin[1]);
    for (int i = 2; i < 55; i++) {
        putchar(' ');
        print(origin[i]);
    }
    putchar('\n');
    return 0;
}
