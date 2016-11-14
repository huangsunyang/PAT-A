//
//  main.cpp
//  1113
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> vec;
    int n, temp, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n / 2; i++) {
        sum -= vec[i];
    }
    for (int i = n / 2; i < n; i++) {
        sum += vec[i];
    }
    printf("%d %d\n", n % 2 == 0 ? 0 : 1, sum);
    return 0;
}
