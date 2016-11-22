//
//  main.cpp
//  1095
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define IN 0
#define OUT 1
#include <string>
using namespace std;

struct car {
    char name[10];
    int in_out_time;
    int in_or_out;
//    car & operator = (car a) {
//        strcpy(name, a.name);
//        in_out_time = a.in_out_time;
//        in_or_out = a.in_or_out;
//        return *this;
//    }
};

int trans_time_to_int(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}

void print_time(int n) {
    int hh = n / 3600;
    n -= hh * 3600;
    int mm = n / 60;
    n -= mm * 60;
    printf("%02d:%02d:%02d", hh, mm, n);
}

bool compare_name(const car & a, const car & b) {
    return strcmp(a.name, b.name) < 0 ||
                (strcmp(a.name, b.name) == 0 && a.in_out_time < b.in_out_time);
}

bool compare_time(const car & a, const car & b) {
    return a.in_out_time < b.in_out_time;
}

struct record {
    int time;
    int num = 0;
};

int bin_search(const vector<record> & rd, int target) {
    if (target < rd[0].time) {
        return 0;
    }
    int st = 0, ed = int(rd.size()) - 1;
    while (ed > st) {
        int mid = (st + ed + 1) / 2;
        if (target >= rd[mid].time) {
            st = mid;
        } else {
            ed = mid - 1;
        }
    }
    return rd[st].num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, q;
    vector<car> all_cars;
    vector<car> real_cars;
    vector<record> records;
    scanf("%d %d", &n, &q);
    car temp_car;
    char in_out_temp[5];
    vector<string> max_string;
    for (int i = 0; i < n; i++) {
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", temp_car.name, &hh, &mm, &ss, in_out_temp);
        temp_car.in_out_time = trans_time_to_int(hh, mm, ss);
        if (in_out_temp[0] == 'i') {
            temp_car.in_or_out = IN;
        } else temp_car.in_or_out = OUT;
        all_cars.push_back(temp_car);
    }
    int max = -1;
    sort(all_cars.begin(), all_cars.end(), compare_name);
    for (int i = 0; i < all_cars.size(); i++) {
        int j = i + 1;
        if (j < all_cars.size() && strcmp(all_cars[i].name, all_cars[j].name) == 0
            && all_cars[i].in_or_out == IN && all_cars[j].in_or_out == OUT) {
            real_cars.push_back(all_cars[i]);
            real_cars.push_back(all_cars[j]);
            i = j;
        }
    }
    sort(real_cars.begin(), real_cars.end(), compare_time);
    int st = 0;
    for (int i = 0; i < real_cars.size(); i++) {
        if (real_cars[i].in_or_out == IN) {
            record temp;
            temp.num = ++st;
            temp.time = real_cars[i].in_out_time;
            records.push_back(temp);
        } else {
            record temp;
            temp.num = --st;
            temp.time = real_cars[i].in_out_time;
            records.push_back(temp);
        }
    }
    for (int i = 0; i < q; i++) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = trans_time_to_int(hh, mm, ss);
        printf("%d\n", bin_search(records, time));
    }
    
    sort(real_cars.begin(), real_cars.end(), compare_name);
    for (int i = 0; i < real_cars.size(); i++) {
        int j, dif = 0;
        for (j = i; j < real_cars.size(); j++) {
            if (strcmp(real_cars[j].name, real_cars[i].name) != 0) {
                break;
            }
            if (real_cars[j].in_or_out == IN) {
                dif -= real_cars[j].in_out_time;
            } else dif += real_cars[j].in_out_time;
        }
        if (dif > max) {
            max = dif;
            max_string.clear();
            max_string.push_back(string(real_cars[i].name));
        } else if (dif == max) {
            max_string.push_back(string(real_cars[i].name));
        }
        i = j - 1;
    }
    for (int i = 0; i < max_string.size(); i++) {
        printf("%s ", max_string[i].c_str());
    }
    print_time(max);
    putchar('\n');
    return 0;
}
