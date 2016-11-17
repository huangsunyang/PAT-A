//
//  main.cpp
//  1040
//
//  Created by huangsunyang on 11/17/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    char str[1001];
    scanf("%[^\n]", str);
    //printf("%s\n",str);
    int max = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int j = i - 1, k = i + 1, cur_max = 1;
        while (j >= 0 && str[k] != '\0' && str[j] == str[k]) {
            cur_max += 2;
            j--, k++;
        }
        if (cur_max > max) {
            max = cur_max;
        }
        j = i, k = i + 1, cur_max = 0;
        while (j >= 0 && str[k] != '\0' && str[j] == str[k]) {
            cur_max += 2;
            j--, k++;
        }
        if (cur_max > max) {
            max = cur_max;
        }
    }
    printf("%d\n", max);
    return 0;
}
