//
//  main.cpp
//  1081
//
//  Created by huangsunyang on 11/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    if (a == 0) return 1;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a < b) {
        std::swap(a, b);
    }
    while (a % b != 0) {
        int k = b;
        b = a % b;
        a = k;
    }
    return b;
}

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    if (a.second < 0) {
        a.second *= -1;
        a.first *= -1;
    }
    if (b.second < 0) {
        a.second *= -1;
        a.first *= -1;
    }
    int d = a.second * b.second;
    int c = a.first * b.second + b.first * a.second;
    int common = gcd(c, d);
    d /= common;
    c /= common;
    return make_pair(c, d);
}

void print(pair<int, int> a) {
    if (a.first < 0) {
        printf("-");
        a.first *= -1;
        print(a);
        return;
    }
    if (a.first == 0) {
        printf("0\n");
        return;
    }
    if (a.second == 1) {
        printf("%d\n", a.first);
        return;
    }
    if (a.first > a.second) {
        printf("%d ", a.first / a.second);
        a.first %= a.second;
    }
    printf("%d/%d", a.first, a.second);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    pair<int, int> start = make_pair(0, 1);
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d/%d", &a, &b);
        start = add(start, make_pair(a, b));
    }
    print(start);
    return 0;
}
