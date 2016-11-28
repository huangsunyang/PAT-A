//
//  main.cpp
//  1061
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
using namespace std;

char weekdays[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int found_pos[128];
int find_times[128];
int real_pos[128];
int main(int argc, const char * argv[]) {
    string a, b, c, d;
    cin>>a>>b>>c>>d;
    for (int i = 0; i < 128; i++) {
        found_pos[i] = 0x7FFFFFFF;
        real_pos[i] = 0x7FFFFFFF;
    }
    int weekday, hour;
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
            weekday = a[i];
            i++;
            break;
        }
    }
    weekday -= 'A';
    for (; i < a.size() && i < b.size(); i++) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || (a[i] >= '0' && a[i] <= '9'))) {
            hour = a[i];
            break;
        }
    }
    if (hour <= 'N' && hour >= 'A') {
        hour = hour - 'A' + 10;
    } else {
        hour -= '0';
    }
    int min = 0;
    for (int j = 0; j < c.size() && j < d.size(); j++) {
        if (c[j] == d[j] && isalpha(c[j])) {
            min = j;
            break;
        }
    }
    printf("%s %02d:%02d\n", weekdays[weekday], hour, min);
    return 0;
}
