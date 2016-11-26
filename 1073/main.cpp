//
//  main.cpp
//  1073
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int get_number(const char * p) {
    return int(strtol(p, NULL, 10));
}

void print_zero(int n) {
    while (n--) {
        putchar('0');
    }
}

int main(int argc, const char * argv[]) {
    string s;
    char c = getchar();
    if (c == '-') {
        putchar('-');
    }
    cin>>s;
    int Epos = int(s.find('E'));
    int dotPos = int(s.find('.'));
    string after = s.substr(Epos + 1);
    int d = get_number(after.c_str());
    if (d == 0) {
        cout<<s.substr(0, Epos);
    } else if(d > 0) {
        string a = s.substr(0, dotPos);
        string b = s.substr(dotPos + 1, Epos - dotPos - 1);
        if (b.length() <= d) {
            cout<<a<<b;
            print_zero(int(d - b.length()));
        } else {
            cout<<a<<b.substr(0, d);
            cout<<'.'<<b.substr(d);
        }
    } else if(d < 0) {
        d *= -1;
        string a = s.substr(0, dotPos);
        string b = s.substr(dotPos + 1, Epos - dotPos - 1);
        if (a.length() <= d) {
            cout<<"0.";
            print_zero(int(d - a.length()));
            cout<<a<<b;
        }
    }
    return 0;
}
