//
//  main.cpp
//  1033
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct station {
    station(){}
    station(double a, double b): dis(a), price(b){};
    double price;
    double dis;
    bool operator < (const station & a) const {
        return dis < a.dis;
    }
};

int main(int argc, const char * argv[]) {
    double c, dis, dis_per_gas, n;
    scanf("%lf %lf %lf %lf", &c, &dis, &dis_per_gas, &n);
    vector<station> stations;
    for (int i = 0; i < n; i++) {
        station temp;
        scanf("%lf %lf", &temp.price, &temp.dis);
        stations.push_back(temp);
    }
    sort(stations.begin(), stations.end());
    stations.push_back(station(dis, 0));
    double cur_cost = 0, cur_gas = 0, max_dis = -1;
    if (stations[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    for (int i = 0; i < stations.size() - 1; i++) {
        double cheapest = 0x7FFFFFFF, cheapest_pos = i;
        int j;
        bool cheaper = false, can_reach = false;
        for (j = i + 1; j < stations.size() &&
             stations[j].dis - stations[i].dis <= c * dis_per_gas; j++) {
            if (stations[j].price < stations[i].price) {
                cur_cost += ((stations[j].dis - stations[i].dis) / dis_per_gas - cur_gas) * stations[i].price;
                cur_gas = 0;
                cheaper = can_reach = true;
                i = j - 1;
                break;
            }
            else {
                if (stations[j].price < cheapest) {
                    cheapest = stations[j].price;
                    cheapest_pos = j;
                    can_reach = true;
                }
            }
        }
        if (!can_reach) {
            max_dis = stations[i].dis + c * dis_per_gas;
            break;
        }
        if (!cheaper) {
            cur_cost += (c - cur_gas) * stations[i].price;
            cur_gas = c - (stations[cheapest_pos].dis - stations[i].dis) / dis_per_gas;
            i = cheapest_pos - 1;
        }
    }
    if (max_dis != -1) {
        printf("The maximum travel distance = %.2lf\n", max_dis);
    } else {
        printf("%.2lf\n", cur_cost);
    }
    
    return 0;
}
