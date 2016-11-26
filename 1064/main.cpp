//
//  main.cpp
//  1064
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void in_order(vector<int> &tree, int root, vector<int> & st) {
    if (2 * root + 1 < tree.size()) {
        in_order(tree, 2 * root + 1, st);
    }
    tree[root] = st.back();
    st.pop_back();
    if (2 * root + 2 < tree.size()) {
        in_order(tree, 2 * root + 2, st);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    vector<int> vec(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), std::greater<int>());
    in_order(vec, 0, v);
    printf("%d", vec[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", vec[i]);
    }
    putchar('\n');
    return 0;
}
