//
//  main.cpp
//  1055
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct people {
    char name[10];
    int age;
    int money;
    bool operator < (const people &b) const {
        if (money != b.money) {
            return money > b.money;
        } else if (age != b.age) {
            return age < b.age;
        } else {
            return strcmp(name, b.name) < 0;
        }
    }
};

vector<people> bucket;
vector<people> first;
int sizes[201];
int n, q;

void print(const people &p) {
    printf("%s %d %d\n", p.name, p.age, p.money);
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        people t;
        scanf("%s %d %d", t.name, &t.age, &t.money);
        first.push_back(t);
    }
    sort(first.begin(), first.end());
    for (int i = 0; i < first.size(); i++) {
        if (sizes[first[i].age] <= 100) {
            bucket.push_back(first[i]);
            sizes[first[i].age]++;
        }
    }
    for (int i = 1; i <= q; i++) {
        int num, age_min, age_max;
        scanf("%d %d %d", &num, &age_min, &age_max);
        printf("Case #%d:\n", i);
        bool empty = true;
        int index = 0;
        for (int j = 0; j < bucket.size(); j++) {
            if (bucket[j].age >= age_min && bucket[j].age <= age_max && index < num) {
                print(bucket[j]);
                empty = false;
                index ++;
            }
        }
        if (empty) {
            printf("None\n");
        }
    }
    return 0;
}
