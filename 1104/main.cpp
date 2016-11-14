//
//  main.cpp
//  1104
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
double sum2(vector<double> vec) {
    double sum = 0;
    for (int i = 0, sz = int(vec.size()); i < vec.size(); i++, sz--) {
        sum += vec[i] * sz * (i + 1);
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    double temp;
    vector<double> vec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &temp);
        vec.push_back(temp);
    }
    double sum = 0;
    sum = sum2(vector<double>(vec.begin(), vec.end()));
    printf("%.2lf", sum);
    return 0;
}
