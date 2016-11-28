//
//  main.cpp
//  1060
//
//  Created by huangsunyang on 11/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <utility>
using namespace std;

pair<string, int> trans(string a, int n) {
    string ret;
    size_t pos = a.find('.');
    if (pos == string::npos) {
        ret += "0.";
        if (a.size() >= n) {
            ret += a.substr(0, n);
        } else {
            ret += a;
            ret += string(n - a.size(), '0');
        }
        if (a.size() == 1 && a[0] == '0') {
            a.pop_back();
        }
        return make_pair(ret, a.size());
    } else {
        if (a.size() - 2 < n) {
            a += string(n + 2 - a.size(), '0');
        }
        
        a = a.substr(0, pos) + a.substr(pos + 1);
        size_t p = a.find_first_not_of('0');
        if (p == string::npos) {
            ret = "0." + string(n, '0');
            return make_pair(ret, 0);
        }
        else a = a.substr(p);
        a += string(p, '0');
        ret = "0." + a.substr(0, n);
        return make_pair(ret, pos - p);
        
    }
    return make_pair(" ", 0);
}

void print(pair<string, int> a) {
    cout<<a.first<<"*"<<10<<"^"<<a.second;
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d", &n);
    string a, b;
    cin>>a>>b;
    pair<string, int> ret_a = trans(a, n);
    pair<string, int> ret_b = trans(b, n);
    if (ret_b == ret_a) {
        printf("YES ");
        print(ret_a);
    } else {
        printf("NO ");
        print(ret_a);
        putchar(' ');
        print(ret_b);
    }
    putchar('\n');
    return 0;
}
