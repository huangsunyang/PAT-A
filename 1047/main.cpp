//
//  main.cpp
//  1047
//
//  Created by huangsunyang on 12/5/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(const char * a, const char * b) {
    return strcmp(a, b) < 0;
}

int main(int argc, const char * argv[]) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<vector<char *> > vec(k + 1, vector<char *>());
    for (int i = 0; i < n; i++) {
        char * name = new char[5];
        int num;
        scanf("%s %d", name, &num);
        for (int j = 0; j < num; j++) {
            int temp;
            scanf("%d", &temp);
            vec[temp].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        printf("%d %lu\n", i, vec[i].size());
        if (!vec[i].empty()) {
            sort(vec[i].begin(), vec[i].end(), compare);
            for (int j = 0; j < vec[i].size(); j++) {
                printf("%s\n", vec[i][j]);
            }
        }
    }
    return 0;
}
