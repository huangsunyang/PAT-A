//
//  main.cpp
//  1039
//
//  Created by huangsunyang on 12/5/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare (const char * a, const char * b) {
    return strcmp(a, b) == 0;
}

size_t hasher(char * a) {
    return a[0] * 128 * 128 * 128 + a[1] * 128 * 128 + a[2] * 128 + a[3];
}

int main(int argc, const char * argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    unordered_map<char *, vector<int>, decltype(hasher)*, decltype(compare)*> mp(120000, hasher, compare);
    for (int i = 0; i < k; i++) {
        int course, num;
        scanf("%d %d", &course, &num);
        for (int i = 0; i < num; i++) {
            char * temp = new char[5];
            scanf("%s", temp);
            mp[temp].push_back(course);
        }
    }
    for (int i = 0; i < n; i++) {
        char temp[5];
        scanf("%s", temp);
        printf("%s", temp);
        vector<int> &vec = mp[temp];
        if (!vec.empty()) {
            printf(" %lu", vec.size());
            sort(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); i++) {
                printf(" %d", vec[i]);
            }
        } else printf(" 0");
        
        putchar('\n');
    }
    return 0;
}
