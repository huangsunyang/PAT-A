//
//  main.cpp
//  1058
//
//  Created by huangsunyang on 11/29/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int a1, a2, a3, b1, b2, b3;
    int c1, c2, c3;
    scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
    int flag = 0;
    flag = (a3 + b3) / 29;
    c3 = (a3 + b3) % 29;
    c2 = (a2 + b2 + flag) % 17;
    flag = (a2 + b2 + flag) / 17;
    c1 = a1 + b1 + flag;
    printf("%d.%d.%d\n", c1,c2,c3);
    return 0;
}
