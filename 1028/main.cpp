//
//  main.cpp
//  1028
//
//  Created by huangsunyang on 10/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;
struct student {
    //student(string a, string b, int c): id(a), name(b), score(c){}
    int id;
    char name[20];
    int score;
    void print() {
        printf("%06d %s %d\n", id, name, score);
    }
};

bool sort1(const student a, const student b) {
    return a.id < b.id;
}
bool sort2(const student a, const student b) {
    return strcmp(a.name, b.name) < 0 || (strcmp(a.name, b.name) == 0 && a.id < b.id);
}
bool sort3(const student a, const student b) {
    return a.score < b.score || (a.score == b.score && a.id < b.id);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::ios::sync_with_stdio(false);
    vector<student> students;
    student temp;
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &temp.id, temp.name, &temp.score);
        students.push_back(temp);
    }
    if (c == 1) {
        sort(students.begin(), students.end(), sort1);
    } else if (c == 2) {
        sort(students.begin(), students.end(), sort2);
    }
    else {
        sort(students.begin(), students.end(), sort3);
    }
    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    return 0;
}
