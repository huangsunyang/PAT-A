//
//  main.cpp
//  1052
//
//  Created by huangsunyang on 11/17/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int num;
    int value;
    int next;
    bool operator < (const node & b) const {
        return value < b.value;
    }
    node & operator = (const node & b) {
        num = b.num;
        value = b.value;
        next = b.next;
        return *this;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<node> vec;
    map<int, node> mp;
    node temp;
    int n, head;
    scanf("%d %d", &n, &head);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &temp.num, &temp.value, &temp.next);
        mp[temp.num] = temp;
    }
    while (mp.find(head) != mp.end()) {
        node t = mp[head];
        vec.push_back(t);
        head = t.next;
    }
    sort(vec.begin(), vec.end());
//    for_each(vec.begin(), vec.end(),
//             [](node n){printf("%05d %d %05d\n", n.num, n.value, n.next);});
    if (vec.size() == 0) {
        printf("0 %d\n", -1);
        return 0;
    }
    printf("%lu %05d\n", vec.size(), vec[0].num);
    for (int i = 0; i < vec.size() - 1; i++) {
        printf("%05d %d %05d\n", vec[i].num, vec[i].value, vec[i + 1].num);
    }
    int i = int(vec.size()) - 1;
    printf("%05d %d %d\n", vec[i].num, vec[i].value, -1);
    return 0;
}
