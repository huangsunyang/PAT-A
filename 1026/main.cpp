//
//  main.cpp
//  1026
//
//  Created by huangsunyang on 10/16/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>
using namespace std;

struct custom {
    int arrive_time;
    int waiting_time;
    int need_time;
    bool is_vip;
    custom(int a, int b, bool c): arrive_time(a), need_time(b), is_vip(c), waiting_time(0){}
    bool operator < (const custom & c) const {
        return arrive_time < c.arrive_time;
    }
    void print() const{
        int hh, mm, ss, t;
        t = arrive_time;
        hh = t / 3600;
        mm = (t % 3600) / 60;
        ss = t % 60;
        printf("%02d:%02d:%02d ", hh, mm, ss);
        t = arrive_time + waiting_time;
        hh = t / 3600;
        mm = (t % 3600) / 60;
        ss = t % 60;
        printf("%02d:%02d:%02d ", hh, mm, ss);
        printf("%d\n", int(round(waiting_time/60.0)));
    }
};

bool compare(const custom & a, const custom & b) {
    return a.arrive_time + a.waiting_time < b.arrive_time + b.waiting_time;
}

int has_tables(vector<bool> &avail) {
    for (int i = 0; i < avail.size(); i++) {
        if (avail[i]) {
            return i;
        }
    }
    return -1;
}

int has_vip_tables(vector<bool> & avail, vector<int> & vip) {
    for (int i = 0; i < vip.size(); i++) {
        if (avail[vip[i]]) {
            return vip[i];
        }
    }
    return -1;
}

int cur_time, k;
queue<int> ord_customs, vip_customs;

void find_a_table(vector<int> &free_time, vector<bool> &available, vector<custom> &customs) {
    int temp = *min_element(free_time.begin(), free_time.end());
    //printf("find a first table free at %d\n", temp + cur_time);
//    for (int i = 0; i<free_time.size(); i++) {
//        printf("%d ",free_time[i]);
//    }
//    putchar('\n');
    for (int i = 0; i < free_time.size(); i++) {
        free_time[i] -= temp;
        if (free_time[i] <= 0) {
            free_time[i] = 0;
            available[i] = true;
        }
    }
    cur_time += temp;
}

void time_passed(int t, vector<int> &free_time, vector<bool> &available) {
    //printf("time passed %d at %d\n", t, cur_time);
    cur_time += t;
    for (int i = 0; i < free_time.size(); i++) {
        free_time[i] -= t;
        if (free_time[i] <= 0) {
            free_time[i] = 0;
            available[i] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, hh, mm, ss, temp_need, tag;
    int table_num, vip_num;
    vector<custom> customs;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &temp_need, &tag);
        if (temp_need > 120) temp_need = 120;
        customs.push_back(custom(hh * 3600 + mm * 60 + ss, temp_need * 60, tag));
    }
    std::sort(customs.begin(), customs.end(), std::less<custom>());
    for (int i = 0; i < customs.size(); i++) {
        if (customs[i].is_vip) {
            vip_customs.push(i);
        } else ord_customs.push(i);
    }
    scanf("%d %d", &table_num, &vip_num);
    vector<int> tables(n);
    vector<bool> available(table_num, true);
    vector<int> free_time(table_num, 0);
    vector<int> served_people(table_num, 0);
    vector<int> vip_tables;
    for (int i = 0; i < vip_num; i++) {
        int temp;
        scanf("%d", &temp);
        vip_tables.push_back(temp-1);
    }
    cur_time = customs[0].arrive_time;
    while (!ord_customs.empty() || !vip_customs.empty()) {
//        if (cur_time >= 21 * 3600) {
//            break;
//        }
        int first_custom_time = 0x7FFFFFFF;
        if (ord_customs.empty()) {
            first_custom_time = customs[vip_customs.front()].arrive_time;
        } else if (vip_customs.empty())
            first_custom_time = customs[ord_customs.front()].arrive_time;
        else {
            first_custom_time = min(customs[vip_customs.front()].arrive_time, customs[ord_customs.front()].arrive_time);
        }
        if (cur_time < first_custom_time) {
            time_passed(first_custom_time - cur_time, free_time, available);
            continue;
        }
        int try_find_vip_table = has_vip_tables(available, vip_tables);
        if (try_find_vip_table != -1 && !vip_customs.empty() && customs[vip_customs.front()].arrive_time <= cur_time) {
            int vf = vip_customs.front();
//            printf("%d arrives at %d and got a vip seat: %d at %d and leaves at %d\n", vf, customs[vf].arrive_time, try_find_vip_table, cur_time, customs[vf].need_time + cur_time);
            vip_customs.pop();
            customs[vf].waiting_time = cur_time - customs[vf].arrive_time;
            available[try_find_vip_table] = false;
            if(cur_time < 21 * 3600)
                served_people[try_find_vip_table]++;
            free_time[try_find_vip_table] = customs[vf].need_time;
        } else if (has_tables(available) != -1) {         //说明能找到一个桌子
            int try_find_table = has_tables(available);
            if (ord_customs.empty()) {
                k = vip_customs.front();
                vip_customs.pop();
            } else if (vip_customs.empty()) {
                k = ord_customs.front();
                ord_customs.pop();
            } else if (customs[vip_customs.front()].arrive_time < customs[ord_customs.front()].arrive_time) {
                k = vip_customs.front();
                vip_customs.pop();
            } else {
                k = ord_customs.front();
                ord_customs.pop();
            }
//            printf("%d arrives at: %d got an common seat: %d at %d and leaves at %d\n", k, customs[k].arrive_time, try_find_table ,cur_time, cur_time + customs[k].need_time);
            customs[k].waiting_time = cur_time - customs[k].arrive_time;
            available[try_find_table] = false;
            if(cur_time < 21 * 3600)
                served_people[try_find_table]++;
            free_time[try_find_table] = customs[k].need_time;
        } else {
            //printf("Try find a table at %d...\n", cur_time);
            find_a_table(free_time, available, customs);
        }
    }
    sort(customs.begin(), customs.end(), compare);
    for (int i = 0; i < customs.size(); i++) {
        if (customs[i].arrive_time + customs[i].waiting_time < 21 * 3600)
            customs[i].print();
    }
    printf("%d", served_people[0]);
    for (int i = 1; i < served_people.size(); i++) {
        printf(" %d", served_people[i]);
    }
    putchar('\n');
    return 0;
}
