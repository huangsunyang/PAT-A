//
//  main.cpp
//  1101
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, temp;
    scanf("%d", &n);
    vector<int> vec, vec2, minin(n), maxin;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    maxin.push_back(vec[0]);
    for (int i = 1; i < n; i++) {
        maxin.push_back(std::max(maxin[i - 1], vec[i]));
    }
    minin[n - 1] = vec[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minin[i] = std::min(minin[i + 1], vec[i]);
    }
    minin.push_back(0x7FFFFFFF);
    if (vec[0] < minin[1]) {
        vec2.push_back(vec[0]);
    }
    for (int i = 1; i < vec.size(); i++) {
        if(vec[i] > maxin[i - 1] && minin[i + 1] > vec[i]) {
            vec2.push_back(vec[i]);
        }
    }
    sort(vec2.begin(), vec2.end());
    printf("%lu\n", vec2.size());
    for (int i = 0; i < vec2.size(); i++) {
        if(i == 0) printf("%d", vec2[i]);
        else printf(" %d", vec2[i]);
    }
    putchar('\n');
    return 0;
}
