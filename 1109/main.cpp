//
//  main.cpp
//  1109
//
//  Created by huangsunyang on 11/5/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string.h>
struct person {
    char name[13];
    int height;
};

bool compare(person a, person b) {
    return a.height < b.height || ((a.height == b.height) && strcmp(a.name, b.name) > 0);
}

int main(int argc, const char * argv[]) {
    int n, k;
    std::vector<person> vec;
    person temp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", temp.name, &temp.height);
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end(), compare);
    int gap = n / k;
    int flag = 1;
    for (int i = gap * (k - 1); i >= 0; i -= gap) {
        int j;
        int flag2 = 1;
        if ((flag ? n - i: gap) % 2 == 0) {
            j = i;
        } else {
            j = i + 1;
        }
        for (; j < (flag ? n : i + gap); j += 2) {
            if(j == i || j == i + 1) printf("%s", vec[j].name);
            else printf(" %s", vec[j].name);
            flag2 = 0;
        }
        for (int j = (flag ? n - 1 : i + gap - 1); j >= i; j -= 2) {
            if(flag2 && j == (flag ? n - 1 : i + gap - 1)) printf("%s", vec[j].name);
            else printf(" %s", vec[j].name);
        }
        putchar('\n');
        flag = 0;
    }
    return 0;
}
