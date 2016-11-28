//
//  main.cpp
//  1071
//
//  Created by huangsunyang on 11/27/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <ctype.h>
using namespace std;
int main(int argc, const char * argv[]) {
    string all;
    std::getline(std::cin, all);
    for (int i = 0; i < all.size(); i++) {
        if (all[i] <= 'Z' && all[i] >= 'A') {
            all[i] += 'a' - 'A';
        }
        if (!isalnum(all[i])) {
            all[i] = ' ';
        }
    }
    stringstream s(all);
    string temp;
    vector<string> vec;
    while (s>>temp) {
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int n = int(vec.size());
    string fin;
    int max = -1;
    for (int i = 0; i < n; i++) {
        int j, ret = 1;
        for (j = i + 1; j < n && vec[j] == vec[i]; j++) {
            ret++;
        }
        if (ret > max) {
            max = ret;
            fin = vec[i];
        }
        i = j - 1;
    }
    cout<<fin<<' '<<max<<'\n';
    return 0;
}
