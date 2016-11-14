//
//  main.cpp
//  1119
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
vector<int> fin;
bool is_unique(deque<int> a, deque<int> b) {
    if(a.empty()) return true;
    int t = a[0];
    a.pop_front();
    b.pop_back();
    if (a.empty()) {
        fin.push_back(t);
        return true;
    }
    vector<int> temp1, temp2;
    int num = 0, sign = 1;
    bool tag = true;
    for (int i = 0; i < a.size(); i++) {
        temp1.push_back(a[i]);
        temp2.push_back(b[i]);
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (equal(temp1.begin(), temp1.end(), temp2.begin())) {
            num ++;
            sign = i + 1;
            break;
        }
    }
    if (sign == a.size()) {
        tag = false;
    }
    bool tag1 = is_unique(deque<int>(a.begin(), a.begin() + sign),
                          deque<int>(b.begin(), b.begin() + sign));
    fin.push_back(t);;
    bool tag2 = is_unique(deque<int>(a.begin() + sign, a.end()),
                          deque<int>(b.begin() + sign, b.end()));
    return tag && tag1 && tag2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, temp;
    deque<int> pre, post;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        pre.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        post.push_back(temp);
    }
    printf("%s\n", is_unique(pre, post) ? "Yes" : "No");
    printf("%d",fin[0]);
    for (int i = 1; i < fin.size(); i++) {
        printf(" %d", fin[i]);
    }
    putchar('\n');
    return 0;
}
