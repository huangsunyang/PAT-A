//
//  main.cpp
//  1032
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id;
    char key;
    int next;
};

node link[100003];

int main(int argc, const char * argv[]) {
    int st1, st2, n;
    scanf("%d %d %d", &st1, &st2, &n);
    for (int i = 0; i < n; i++) {
        node temp;
        scanf("%d %c %d", &temp.id, &temp.key, &temp.next);
        link[temp.id] = temp;
    }
    vector<int> vec1, vec2;
    while (st1 != -1) {
        vec1.push_back(st1);
        st1 = link[st1].next;
    }
    while (st2 != -1) {
        vec2.push_back(st2);
        st2 = link[st2].next;
    }
    //短路没考虑到！！！
    if ( vec1.empty() || vec2.empty() || vec1.back() != vec2.back()) {
        printf("-1\n");
    } else {
        int i = int(vec1.size()) - 1;
        int j = int(vec2.size()) - 1;
        for (; i >= 0 && j >= 0 && vec1[i] == vec2[j]; i--, j--) {
        }
        printf("%05d\n", vec1[i + 1]);
    }
    return 0;
}
