//
//  main.cpp
//  1114
//
//  Created by huangsunyang on 11/20/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
    int id;
    int father, mother;
    vector<int> children;
    int estate_num;
    int aera;
    bool has_found;
};

struct info {
    int least_id;
    int num;
    int estate_num, aera;
};

info& operator += (info& temp, const info& b) {
    temp.least_id = std::min(temp.least_id, b.least_id);
    temp.num += b.num;
    temp.aera += b.aera;
    temp.estate_num += b.estate_num;
    return temp;
}

info operator + (const info& a, const info& b) {
    info temp = a;
    return temp += b;
}

person ar[10000];
info search_parents(int id);

info get_info(int id) {
    info temp;
    temp.least_id = id;
    temp.num = 1;
    temp.estate_num = ar[id].estate_num;
    temp.aera = ar[id].aera;
    return temp;
}

info search_children(int id) {
    ar[id].has_found = true;
    info temp = get_info(id);
    for (int i = 0; i < ar[id].children.size(); i++) {
        if (ar[id].children[i] == -1 || ar[ar[id].children[i]].has_found) {
            continue;
        }
        temp += search_children(ar[id].children[i]);
    }
    return temp;
}

info search_all(int id) {
    return search_children(id);
}

bool compare(const info & a, const info & b) {
    double a1 = a.aera * 1.0 / a.num;
    double b1 = b.aera * 1.0 / b.num;
    return a1 > b1 || (a1 == b1 && a.least_id < b.least_id);
}

void print(info a) {
    printf("%04d %d %.3lf %.3lf\n", a.least_id, a.num, a.estate_num * 1.0 / a.num,
           a.aera * 1.0 / a.num);
}

int main(int argc, const char * argv[]) {
    vector<info> fin;
    int n, k, t;
    for (int i = 0; i < 10000; i++) {
        ar[i].id = -1;
        ar[i].aera = 0;
        ar[i].estate_num = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r;
        scanf("%d", &r);
        ar[r].id = r;
        scanf("%d %d %d", &ar[r].father, &ar[r].mother, &k);
        if(ar[r].father >= 0)
            ar[ar[r].father].children.push_back(r);
        if(ar[r].mother >= 0)
            ar[ar[r].mother].children.push_back(r);
        for (int i = 0; i < k; i++) {
            scanf("%d", &t);
            ar[r].children.push_back(t);
            ar[t].children.push_back(r);
        }
        ar[r].children.push_back(ar[r].father);
        ar[r].children.push_back(ar[r].mother);
        scanf("%d %d", &ar[r].estate_num, &ar[r].aera);
        ar[r].has_found = false;
    }
    for (int i = 0; i < 10000; i++) {
        if (!ar[i].children.empty() && !ar[i].has_found) {
            fin.push_back(search_all(i));
        }
    }
    sort(fin.begin(), fin.end(), compare);
    printf("%lu\n", fin.size());
    for (int i = 0; i < fin.size(); i++) {
        print(fin[i]);
    }
    return 0;
}
