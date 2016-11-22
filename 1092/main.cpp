//
//  main.cpp
//  1092
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
int num[200];

int main(int argc, const char * argv[]) {
    char shop[1003], want[1003];
    scanf("%s %s", shop, want);
    for (char * ptr = want; *ptr != '\0'; ptr++) {
        num[*ptr]++;
    }
    for (char * ptr = shop; *ptr != '\0'; ptr++) {
        num[*ptr]--;
    }
    int bigger_than_0 = 0;
    int total_num = 0;
    bool all_smaller_than_0 = true;
    
    for (int i = 0; i < 200; i++) {
        if (num[i] > 0) {
            all_smaller_than_0 = false;
            bigger_than_0 += num[i];
        } else {
            total_num -= num[i];
        }
    }
    if (all_smaller_than_0) {
        printf("Yes %d\n", total_num);
    } else {
        printf("No %d\n", bigger_than_0);
    }
    return 0;
}
