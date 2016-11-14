//
//  main.cpp
//  1016
//
//  Created by huangsunyang on 9/15/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;
struct phone {
    string name;
    int month, day, hour, minute;
    bool on = true;
    phone(string a,int b, int e, int c, int d) {
        name = a;
        day = e;
        month = b;
        hour = c;
        minute = d;
    }
    //计算时间差，单位：分钟
    int minus(phone ph) {
        return 60 * 24 * (day - ph.day) + 60 * (hour - ph.hour) + minute - ph.minute;
    }
    //计算两个时间之间的话费
    int money(phone phone, int* cost) {
        int all_cost = 0, day_cost = 0;
        for(int i = 0; i < 24; i++) {       //计算一整天的话费
            day_cost += cost[i] * 60;
        }
        int total_time = this->minus(phone);
        int day1 = (total_time / (24 * 60));    //计算整天的数量
        //phone.day += day1;
        all_cost += day1 * day_cost;
        all_cost -= phone.minute * cost[phone.hour]; //逼近到下一个小时
        all_cost += minute * cost[hour];             //计算这个小时的
        if(day > phone.day + day1) {            //如果其实并不在同一天，还需要计算小时
            for(int i = phone.hour; i < 24; i++){
                all_cost += 60 * cost[i];
            }
            for(int i = 0; i < hour; i++){
                all_cost += 60 * cost[i];
            }
        } else {                                //如果已经在同一天，只需要计算小时差
            for(int i = phone.hour; i < hour; i++) {
                all_cost += cost[i] * 60;
            }
        }
        return all_cost;
    }
    bool operator < (phone phone) const {
        if(name < phone.name) return true;
        else if(name > phone.name) return false;
        else {
            return day < phone.day || (day == phone.day && hour < phone.hour) ||
            (day == phone.day && hour == phone.hour && minute < phone.minute);
        }
    }
};

int get_num() {
    char a;
    int sum = 0;
    while(!isalnum(a = getchar()));
    sum += (a - '0') * 10;
    a = getchar();
    sum += a- '0';
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int cost[24];
    int month, day, hour, minute, n;
    double total_amount = 0;
    vector<phone> vec;
    string name;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &cost[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin>>name;
        month = get_num();
        day = get_num();
        hour = get_num();
        minute = get_num();
        phone ph(name, month, day, hour, minute);
        cin>>name;
        if(name == "off-line") ph.on = false;
        vec.push_back(ph);
        
    }
    sort(vec.begin(), vec.end());
    string last_name = "";
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0 && !vec[i].on && vec[i - 1].on && vec[i].name == vec[i - 1].name) {
            if (vec[i - 1].name != last_name) {
                if(total_amount != 0) printf("Total amount: $%.2lf\n", total_amount);
                total_amount = 0;
                printf("%s %02d\n", vec[i].name.c_str(), vec[i].month);
                last_name = vec[i].name;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d %d ", vec[i - 1].day, vec[i - 1].hour, vec[i - 1].minute,vec[i].day, vec[i].hour, vec[i].minute, vec[i].minus(vec[i-1]));
            printf("$%.2lf\n", vec[i].money(vec[i-1], cost) / 100.0);
            total_amount +=  vec[i].money(vec[i-1], cost) / 100.0;
        }
    }
    if(total_amount != 0) printf("Total amount: $%.2lf\n", total_amount);
    return 0;
}
