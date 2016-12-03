//
//  main.cpp
//  1036
//
//  Created by huangsunyang on 12/3/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    char name[15];
    char sex;
    char clas[20];
    int grade;
    bool operator < (const student & a) const {
        return grade < a.grade;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    vector<student> boy, girl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        student temp;
        scanf("%s %c %s %d", temp.name, &temp.sex, temp.clas, &temp.grade);
        if (temp.sex == 'M') {
            boy.push_back(temp);
        } else girl.push_back(temp);
    }
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    if (girl.empty()) {
        printf("Absent\n");
    } else printf("%s %s\n", girl.back().name, girl.back().clas);
    if (boy.empty()) {
        printf("Absent\n");
    } else printf("%s %s\n", boy[0].name, boy[0].clas);

    if (!girl.empty() && !boy.empty()) {
        printf("%d\n", girl.back().grade - boy[0].grade);
    } else printf("NA\n");
    return 0;
}
