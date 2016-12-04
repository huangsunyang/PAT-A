//
//  main.cpp
//  1038
//
//  Created by huangsunyang on 12/4/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool print_string(string s) {
    int i;
    for (i = 0; i < s.size(); i++) {
        if (s[i] != '0') {
            break;
        }
    }
    cout<<s.substr(i);
    if (i == s.size()) {
        return true;
    } else return false;
}

bool compare(string a, string b) {
    return a + b < b + a;
}

int main(int argc, const char * argv[]) {
    vector<string> vec;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string temp;
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), compare);
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (first) {
            first = print_string(vec[i]);
        }
        else cout<<vec[i];
    }
    if (first) putchar('0');
    putchar('\n');
    return 0;
}
