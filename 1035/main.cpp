//
//  main.cpp
//  1035
//
//  Created by huangsunyang on 11/18/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<pair<char *, char *> > vec;
    vector<int> record;
    char * account, * password;
    int n, m = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        account = new char[20]();
        password = new char[20]();
        scanf("%s %s", account, password);
        vec.push_back(make_pair(account, password));
    }
    for (int i = 0; i < n; i++) {
        //printf("%s %s\n", vec[i].first, vec[i].second);
        int temp_m = 0;
        for (char * ptr = vec[i].second; * ptr != '\0'; ptr++) {
            temp_m++;
            if (*ptr == '1') {
                *ptr = '@';
            } else if (*ptr == '0') {
                *ptr = '%';
            } else if (*ptr == 'l') {
                *ptr = 'L';
            } else if (*ptr == 'O') {
                *ptr = 'o';
            } else {
                temp_m--;
            }
        }
        if (temp_m > 0) {
            m++;
            record.push_back(i);
        }
    }
    if (m == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    } else {
        printf("%d\n", m);
        for (int i = 0; i < record.size(); i++) {
            printf("%s %s\n", vec[record[i]].first, vec[record[i]].second);
        }
    }
    return 0;
}
