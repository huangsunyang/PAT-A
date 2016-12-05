//
//  main.cpp
//  1037
//
//  Created by huangsunyang on 12/5/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, m, sum = 0, temp;
    vector<int> pos_coup, neg_coup, pos_pro, neg_pro;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp > 0) pos_coup.push_back(temp);
        else neg_coup.push_back(temp);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if (temp > 0) pos_pro.push_back(temp);
        else neg_pro.push_back(temp);
    }
    sort(pos_pro.rbegin(), pos_pro.rend());
    sort(pos_coup.rbegin(), pos_coup.rend());
    int i;
    for (i = 0; i < pos_pro.size() && i < pos_coup.size(); i++) {
        sum += pos_pro[i] * pos_coup[i];
    }
    sort(neg_pro.begin(), neg_pro.end());
    sort(neg_coup.begin(), neg_coup.end());
    for (i = 0; i < neg_coup.size() && neg_pro.size(); i++) {
        sum += neg_pro[i] * neg_coup[i];
    }
    printf("%d\n", sum);
    return 0;
}
