//
//  main.cpp
//  1063
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void differ(vector<int> &a, vector<int> &b) {
    vector<int> temp, temp2;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = int(a.size()), m = int(b.size());
    a.push_back(0x7FFFFFFF);
    b.push_back(0x7FFFFFFF);
    int p = 0, q = 0;
    for (int i = 0; i < n + m; i++) {
        if (a[p] < b[q]) {
            temp.push_back(a[p]);
            p++;
        } else if(a[p] > b[q]) {
            temp.push_back(b[q]);
            q++;
        } else {
            temp.push_back(b[q]);
            temp2.push_back(a[p]);
            p++, q++, i++;
        }
    }
    a.pop_back();
    b.pop_back();
    if(!temp.empty())
        while (temp.back() == 0x7FFFFFFF) {
            temp.pop_back();
        }
    if(!temp2.empty())
        while (temp2.back() == 0x7FFFFFFF) {
            temp2.pop_back();
        }
    size_t all = unique(temp.begin(), temp.end()) - temp.begin();
    size_t common = unique(temp2.begin(), temp2.end()) - temp2.begin();
    printf("%.1lf%%\n", common * 100.0 / all);
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    vector<vector<int> > all(n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int temp;
            scanf("%d", &temp);
            all[i].push_back(temp);
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int q1, q2;
        scanf("%d %d", &q1, &q2);
        differ(all[q1-1], all[q2-1]);
    }
    return 0;
}
