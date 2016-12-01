//
//  main.cpp
//  1054
//
//  Created by huangsunyang on 12/1/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int m, n;
    map<int, int> mp;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            scanf("%d", &t);
            mp[t]++;
        }
    }
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
        if (i->second >= m * n / 2) {
            printf("%d\n", i->first);
            return 0;
        }
    }
    return 0;
}
