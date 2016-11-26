//
//  main.cpp
//  1083
//
//  Created by huangsunyang on 11/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student {
    char name[15];
    char class_name[15];
    int grade;
};

void print(const student & st) {
    printf("%s %s\n", st.name, st.class_name);
}

bool compare(const student & a, const student & b) {
    return a.grade > b.grade;
}

int main(int argc, const char * argv[]) {
    int n, low, high;
    bool one = false;
    vector<student> vec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        student temp;
        scanf("%s %s %d", temp.name, temp.class_name, &temp.grade);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), compare);
    scanf("%d %d", &low, &high);
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].grade <= high && vec[i].grade >= low) {
            one = true;
            print(vec[i]);
        }
    }
    if (!one) {
        printf("NONE\n");
    }
    return 0;
}
