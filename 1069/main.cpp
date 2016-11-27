//
//  main.cpp
//  1069
//
//  Created by huangsunyang on 11/27/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num(int a, int b, int c, int d) {
    return a * 1000 + b * 100 + c * 10 + d;
}
int num(vector<int> vec) {
    return num(vec[0], vec[1], vec[2], vec[3]);
}
vector<int> num_to_vec(int num) {
    vector<int> vec(4);
    vec[0] = num / 1000;
    num %= 1000;
    vec[1] = num / 100;
    num %= 100;
    vec[2] = num / 10;
    num %= 10;
    vec[3] = num;
    return vec;
}
int main(int argc, const char * argv[]) {
    int d;
    scanf("%d", &d);
    vector<int> vec = num_to_vec(d);
    do {
        vector<int> temp1 = vec, temp2 = vec;
        sort(temp1.begin(), temp1.end(), greater<int>());
        sort(temp2.begin(), temp2.end());
        int a = num(temp1), b = num(temp2);
        printf("%04d - %04d = %04d\n", a, b, a-b);
        vec = num_to_vec(a-b);
    } while (num(vec) != 6174 && num(vec) != 0);
    return 0;
}
