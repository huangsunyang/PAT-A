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
struct custom;
struct Table {
    std::vector<int> tables;    //所有的桌子
    std::vector<bool> is_vip;   //是不是vip桌子
    std::vector<int> vip_tables;    //vip桌子编号的集合
    std::vector<int> service_nums;  //每个桌子服务的人数
    int empty_table;            //是否有空桌子
    int vip_table;              //是否有vip桌子
    int current_time = 0;       //当前时间
    int first_empty_table() {
        for(int i = 0; i < tables.size(); i++) {
            if(!tables[i]) return i;
        }
        return -1;
    }
    int first_vip_table() {
        for(int i = 0; i < vip_tables.size(); i++) {
            if(!tables[vip_tables[i]]) return vip_tables[i];
        }
        return -1;
    }
    Table(int a, int b) {
        tables = std::vector<int>(a, 0);
        service_nums = std::vector<int>(a, 0);
        is_vip = std::vector<bool>(a, false);
        empty_table = a;
        vip_table = b;
    }
    void add_custom(custom &c);
    void time_pass(int t);
    int time_passing_to_empty();
};

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
        t = arrive_time;
        hh = t / 3600;
        mm = (t % 3600) / 60;
        ss = t % 60;
        printf("%02d:%02d:%02d ", hh, mm, ss);
        printf("%d\n", waiting_time);
    }
};

int Table::time_passing_to_empty() {
    int min = 0x7fffffff;
    for (int i = 0; i < tables.size(); i++) {
        if(tables[i] == 0) continue;
        min = min > tables[i] ? tables[i] : min;
    }
    time_pass(min);
    return min;
}

void Table::time_pass(int t) {
    for (int i = 0; i < tables.size(); i++) {
        if (tables[i] != 0) {
            tables[i] -= t;
            if(tables[i] <= 0) {
                tables[i] = 0;
                empty_table--;
            }
        }
    }
    current_time += t;
}

void Table::add_custom(custom &c) {
    if(current_time == 0) current_time = c.arrive_time;
    else if(c.arrive_time < current_time) {
        c.waiting_time += current_time - c.arrive_time;
        c.arrive_time = current_time;
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, hh, mm, ss, temp_need, tag;
    int table_num, vip_num;
    std::queue<int> ord_customs, vip_customs;
    std::vector<custom> customs;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &temp_need, &tag);
        customs.push_back(custom(hh * 3600 + mm * 60 + ss, temp_need, tag));
    }
    std::sort(customs.begin(), customs.end(), std::less<custom>());
    scanf("%d %d", &table_num, &vip_num);
    Table tables(table_num, vip_num);
    for (int i = 0; i < vip_num; i++) {
        scanf("%d", &temp_need);
        tables.is_vip[temp_need] = true;
        tables.vip_tables.push_back(temp_need);
    }
    for (int i = 0; i < customs.size(); i++) {
        if (tables.empty_table) {
            tables.add_custom(customs[i]);
        } else {
            if(customs[i].is_vip) {
                vip_customs.push(i);
            } else {
                ord_customs.push(i);
            }
            tables.time_passing_to_empty();
            while (tables.empty_table && (!vip_customs.empty() || !ord_customs.empty())) {
                int first_custom;
                if (ord_customs.empty() || (tables.is_vip[tables.first_empty_table()]
                                            && !vip_customs.empty())){
                    first_custom = vip_customs.front();
                    vip_customs.pop();
                } else if (vip_customs.empty()) {
                    first_custom = ord_customs.front();
                    ord_customs.pop();
                } else {
                    int a = ord_customs.front(), b = vip_customs.front();
                    if(customs[a].arrive_time < customs[b].arrive_time) {
                        first_custom = a;
                        ord_customs.pop();
                    } else {
                        first_custom = b;
                        vip_customs.pop();
                    }
                }
                tables.add_custom(customs[first_custom]);
            }
        }
    }
    for (int i = 0; i < customs.size(); i++) {
        customs[i].print();
    }
    for (int i = 0; i < tables.tables.size(); i++) {
        printf("%d ", tables.service_nums[i]);
    }
    return 0;
}
