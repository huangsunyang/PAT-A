//
//  main.cpp
//  1057
//
//  Created by huangsunyang on 11/19/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowbit(int x) {
    return x & -x;
}

int sum(int * a, int x) {
    int ret = 0;
    while (x > 0) {
        ret += a[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int * a, int x, int d, int n) {
    while (x < n) {
        a[x] += d;
        x += lowbit(x);
    }
}

int find_pos(int * a, int pos) {
    int st = 0, ed = 100000;
    while (ed > st) {
        int mid = (st + ed) / 2;
        int temp = sum(a, mid);
        if(temp >= pos) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    return st;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, temp, c[100005];
    char command[12];
    vector<int> vec;
    for (int i = 0; i < 100005; i++) {
        c[i] = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (command[1] == 'u') {
            scanf("%d", &temp);
            vec.push_back(temp);
            add(c, temp, 1, 100005);
        } else if (command[1] == 'o') {
            if (vec.empty()) {
                printf("Invalid\n");
            }
            else {
                printf("%d\n", vec.back());
                add(c, vec.back(), -1, 100005);
                vec.pop_back();
            }
        } else {
            if (vec.empty()) {
                printf("Invalid\n");
            }
            else {
                printf("%d\n", find_pos(c, int(vec.size() + 1) / 2));
            }
        }
    }
    return 0;
}
