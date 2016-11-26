//
//  main.cpp
//  1077
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int n;
    string temp;
    vector<string> vec;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        for (int i = 0; i < temp.size() / 2; i++) {
            std::swap(temp[i], temp[temp.size() - 1 - i]);
        }
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    string a = vec[0], b = vec.back();
    int total = 0;
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            break;
        } else total++;
    }
    if (total == 0) {
        printf("nai\n");
    } else {
        for (int i = total - 1; i >= 0; i--) {
            putchar(a[i]);
        }
        putchar('\n');
    }
    return 0;
}
