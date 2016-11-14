//
//  main.cpp
//  1006
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class people {
public:
    char name[20];
    int start_time;
    people(char *a, int b) {
        int i = 0;
        while (*a != '\0') {
            name[i++] = *(a++);
        }
        name[i] = '\0';
        start_time = b;
    }
    bool operator< (const people p) const {
        return start_time < p.start_time;
    }
};

int times(int a, int b, int c) {
    return a * 3600 + b * 60 + c;
}
int main(int argc, const char * argv[]) {
    vector<people> vec;
    int hour, minute, seconds, num;
    char names[20];
    char temp1, temp2;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%s", names);
        scanf("%d%c%d%c%d", &hour, &temp1, &minute, &temp2, &seconds);
        vec.push_back(people(names, times(hour, minute, seconds)));
        scanf("%d%c%d%c%d", &hour, &temp1, &minute, &temp2, &seconds);
        vec.push_back(people(names, times(hour, minute, seconds)));
    }
    sort(vec.begin(), vec.end());
    printf("%s %s", vec[0].name, vec[vec.size() - 1].name);
    return 0;
}
