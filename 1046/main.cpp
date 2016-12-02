//
//  main.cpp
//  1046
//
//  Created by huangsunyang on 12/2/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(0);
    scanf("%d", &n);
    int dis, sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &dis);
        sum += dis;
        vec.push_back(dis);
    }
    for (int i = 1; i < vec.size(); i++) {
        vec[i] += vec[i-1];
    }
    int q, a, b;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        if (a < b) {
            std::swap(a, b);
        }
        if ((vec[a] - vec[b]) * 2 <= sum) {
            printf("%d\n", vec[a] - vec[b]);
        } else printf("%d\n", sum - vec[a] + vec[b]);
    }
    return 0;
}
