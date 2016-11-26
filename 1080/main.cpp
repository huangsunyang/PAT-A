//
//  main.cpp
//  1080
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    int ge;
    int gi;
    int id;
    int rank;
    vector<int> choices;
};

bool compare(const student &a, const student &b) {
    if (a.ge + a.gi > b.ge + b.gi) {
        return true;
    } else if(a.ge + a.gi == b.ge + b.gi) {
        return a.ge > b.ge;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int> > schools(m);
    vector<int> quota(m);
    vector<int> counts;
    vector<student> students(n);
    vector<bool> has_found(n, false);
    for (int i = 0; i < m; i++) {
        scanf("%d", &quota[i]);
    }
    for (int i = 0; i < n; i++) {
        students[i].id = i;
        scanf("%d %d", &students[i].ge, &students[i].gi);
        for (int j = 0; j < k; j++) {
            int temp = 0;
            scanf("%d", &temp);
            students[i].choices.push_back(temp);
        }
    }
    sort(students.begin(), students.end(), compare);
    students[0].rank = 0;
    for (int i = 1; i < n; i++) {
        if (students[i].ge + students[i].gi == students[i-1].ge + students[i-1].gi
            && students[i].ge == students[i-1].ge) {
            students[i].rank = students[i-1].rank;
        } else {
            students[i].rank = i;
        }
    }
    int j = 0;
    while (j < n) {
        int i = j;
        for (int p = 0; p < k; p++) {
            for (j = i; j < n && students[j].rank == students[i].rank; j++) {
                int school_num = students[j].choices[p];
                if (quota[school_num] > 0) {
                    if (has_found[students[j].id]) {
                        continue;
                    }
                    schools[school_num].push_back(students[j].id);
                    has_found[students[j].id] = true;
                    //printf("%d %d %d\n", students[j].rank, school_num, students[j].id);
                    counts.push_back(school_num);
                }
            }
            for (int q = 0; q < counts.size(); q++) {
                quota[counts[q]]--;
            }
            counts.clear();
        }
    }
    for (int i = 0; i < m; i++) {
        if (schools[i].empty()) {
            putchar('\n');
            continue;
        } else {
            sort(schools[i].begin(), schools[i].end());
            printf("%d", schools[i][0]);
            for (int j = 1; j < schools[i].size(); j++) {
                printf(" %d", schools[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
