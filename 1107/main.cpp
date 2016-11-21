//
//  main.cpp
//  1107
//
//  Created by huangsunyang on 11/21/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
int hobby[1003];

int find_father(int a) {
    assert(hobby[a] != 0);
    if (hobby[a] != -1) {
        hobby[a] = find_father(hobby[a]);
    }
    else  {
        return a;
    }
    return hobby[a];
}

void union_set(int a, int b) {
    int rt_b = find_father(b);
    hobby[rt_b] = a;
}

int main(int argc, const char * argv[]) {
    
    vector<int> vec, vec2, count;
    for (int i = 0; i < 1003; i++) {
        hobby[i] = 0;
    }
    int n, m, temp, rt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:", &m);
        scanf("%d", &rt);
        vec.push_back(rt);
        if (hobby[rt] == 0) {
            hobby[rt] = -1;
        }

        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            if (hobby[temp] != 0) {
                union_set(rt, temp);
            } else {
                hobby[temp] = rt;
            }
            
        }
    }
    for (int i = 0; i < n; i++) {
        int k = find_father(vec[i]);
        if (vec2.empty()) {
            vec2.push_back(k);
            count.push_back(1);
        }
        else {
            int j;
            bool flag = false;
            for (j = 0; j < vec2.size(); j++) {
                if(k == vec2[j]) {
                    count[j]++;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                vec2.push_back(k);
                count.push_back(1);
            }
        }
    }
    sort(count.begin(), count.end(), std::greater<int>());
    printf("%lu\n", vec2.size());
    printf("%d", count[0]);
    for (int i = 1; i < vec2.size(); i++) {
        printf(" %d", count[i]);
    }
    return 0;
}
