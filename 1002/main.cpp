//
//  main.cpp
//  1002
//
//  Created by huangsunyang on 8/29/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//
#define MIN 0.00001
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
class my_struct {
public:
    int key;
    double value;
    my_struct(int x, double y) {
        key = x;
        value = y;
    }
    bool operator< (const my_struct c) const {
        return key > c.key;
    }
    bool operator> (my_struct& c) const {
        return key < c.key;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int num;
    std::map<int ,double> my_map;
    while (scanf("%d", &num) != EOF) {
        int key;
        double answer;
        while (num--) {
            scanf("%d %lf", &key, &answer);
            my_map[key] += answer;
        }
    }
    std::vector<my_struct> vec;
    std::map<int, double>::iterator it = my_map.begin();
    while (it != my_map.end()) {
        vec.push_back(my_struct(it->first, it->second));
        it++;
    }
    int size = int(vec.size());
    for (std::vector<my_struct>::iterator it = vec.begin(); it != vec.end(); it++) {
        if(fabs(it->value) < MIN)
            size--;
    }
    printf("%d", size);
    std::sort(vec.begin(), vec.end());
    for (std::vector<my_struct>::iterator it = vec.begin(); it != vec.end(); it++) {
        if(fabs(it->value) > MIN)
            printf(" %d %.1lf", it->key, it->value);
    }
    return 0;
}
