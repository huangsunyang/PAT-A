//
//  main.cpp
//  1062
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people {
    int id;
    int virtue;
    int talent;
    int type;
    bool operator < (const people & b) const{
        if(type > b.type) {
            return true;
        } else if(type == b.type) {
            if(virtue + talent > b.virtue + b.talent) {
                return true;
            } else if(virtue + talent == b.virtue + b.talent) {
                if(virtue > b.virtue) {
                    return true;
                } else if (virtue == b.virtue) {
                    if (id < b.id) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
};
int main(int argc, const char * argv[]) {
    int m, l, h;
    vector<people> vec;
    scanf("%d %d %d", &m, &l, &h);
    for (int i = 0; i < m; i++) {
        people temp;
        scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talent);
        if (temp.virtue >= l && temp.talent >= l) {
            if (temp.virtue >= h && temp.talent >= h) {
                temp.type = 4;
            } else if(temp.virtue >= h && temp.talent < h) {
                temp.type = 3;
            } else if (temp.virtue >= temp.talent) {
                temp.type = 2;
            } else {
                temp.type = 1;
            }
            vec.push_back(temp);
        }
    }
    sort(vec.begin(), vec.end());
    printf("%lu\n", vec.size());
    for (int i = 0; i < vec.size(); i++) {
        printf("%d %d %d\n", vec[i].id, vec[i].virtue, vec[i].talent);
    }
    return 0;
}
