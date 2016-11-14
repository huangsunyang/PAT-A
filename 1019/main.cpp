//
//  main.cpp
//  1019
//
//  Created by huangsunyang on 9/25/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> trans(int a, int base) {
    vector<int> vec;
    while (a != 0) {
        vec.push_back(a % base);
        a /= base;
    }
    return vec;
}
bool is_palindromic(vector<int> a) {
    if (a.empty()) {
        return true;
    } else {
        int start = 0, end = int(a.size() - 1);
        while (start < end) {
            if (a[start] != a[end]) {
                return false;
            }
            start++, end--;
        }
        return true;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    vector<int> vec;
    cin>>a>>b;
    vec = trans(a, b);
    if (is_palindromic(vec)) {
        cout<<"Yes"<<endl;
    } else cout<<"No"<<endl;
    if (vec.empty()) {
        printf("0");
    } else {
        printf("%d", vec[vec.size() - 1]);
        for (int i = int(vec.size() - 2); i >= 0; i--) {
            printf(" %d", vec[i]);
        }
    }
    return 0;
}
