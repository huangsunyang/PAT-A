//
//  main.cpp
//  1085
//
//  Created by huangsunyang on 11/18/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bin_search(vector<int> & vec, int target) {
    int st = 0, ed = int(vec.size()) - 1 ;
    while (ed > st) {
        int mid = (st + ed) / 2;
        if (vec[mid] > target) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    if (vec[st] <= target) {
        return st;
    } else return st - 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, p, temp;
    vector<int> vec;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int max_len = -1;
    int max = vec.back(), i;
    for (i = 0; i < n; i++) {
        if (1ll * vec[i] * p >= max) {
            if (int(vec.size()) - i > max_len) {
                max_len = int(vec.size()) - i;
            }
            break;
        } else {
            int target = p * vec[i];
            int cur = bin_search(vec, target) - i + 1;
            max_len = std::max(max_len, cur);
        }
    }
    printf("%d\n", max_len);
    return 0;
}
