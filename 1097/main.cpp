//
//  main.cpp
//  1097
//
//  Created by huangsunyang on 11/21/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
using namespace std;
struct node {
    int id, key, next;
};

node nodes[100000];
bool has_found[10000];
void print_node(node a) {
    if (a.next != -1) {
        printf("%05d %d %05d\n", a.id, a.key, a.next);
    }
    else {
        printf("%05d %d %d\n", a.id, a.key, a.next);
    }
}

int main(int argc, const char * argv[]) {
    int head, n;
    vector<node> first, second;
    node temp;
    scanf("%d %d", &head, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &temp.id, &temp.key, &temp.next);
        nodes[temp.id] = temp;
    }
    int ptr = head;
    while (ptr != -1) {
        if (!has_found[abs(nodes[ptr].key)]) {
            has_found[abs(nodes[ptr].key)] = true;
            if (!first.empty()) {
                first.back().next = nodes[ptr].id;
            }
            first.push_back(nodes[ptr]);
            
        } else {
            if (!second.empty()) {
                second.back().next = nodes[ptr].id;
            }
            second.push_back(nodes[ptr]);
        }
        ptr = nodes[ptr].next;
    }
    if (!first.empty())
        first.back().next = -1;
    if (!second.empty())
        second.back().next = -1;
    for (int i = 0; i < first.size(); i++) {
        print_node(first[i]);
    }
    for (int i = 0; i < second.size(); i++) {
        print_node(second[i]);
    }
    return 0;
}
