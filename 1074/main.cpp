//
//  main.cpp
//  1074
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//
//链表可能有遗漏的，即真实的链表长度可能小于N
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id;
    int key;
    int next;
};

node vec[100000];
void print(const node &a) {
    printf("%05d %d ", a.id, a.key);
    if (a.next == -1) {
        printf("-1\n");
    } else printf("%05d\n", a.next);
}
int main(int argc, const char * argv[]) {
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    vector<node> fin;
    for (int i = 0; i < n; i++) {
        int id, key, next;
        scanf("%d %d %d", &id, &key, &next);
        vec[id].key = key;
        vec[id].next = next;
        vec[id].id = id;
    }
    if (n == 0) {
        printf("-1\n");
        return 0;
    }
    
    while (head != -1) {
        fin.push_back(vec[head]);
        head = vec[head].next;
    }

    for (int i = 0; i < n; i += k) {
        if (i + k > n || k <= 1) {
            break;
        }
        std::reverse(fin.begin() + i, fin.begin() + i + k);
    }
    for (int i = 0; i < n - 1; i++) {
        fin[i].next = fin[i + 1].id;
    }
    fin.back().next = -1;
    for (int i = 0; i < n; i++) {
        print(fin[i]);
    }
    return 0;
}
