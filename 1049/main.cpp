//
//  main.cpp
//  1049
//
//  Created by huangsunyang on 12/2/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int table[20] = {0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000};
int tenpower[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000,
1000000000};

vector<int> int_to_vec(int n) {
    vector<int> ret;
    while (n != 0) {
        ret.push_back(n % 10);
        n /= 10;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    int n, sum = 0;
    scanf("%d", &n);
    vector<int> vec= int_to_vec(n);
    int m = int(vec.size()) - 1;
    for (int i = m; i >= 0; i--) {
        int cur_num = vec[i];
        sum += vec[i] * table[i];
        n -= cur_num * tenpower[i];
        if (vec[i] == 1) {
            sum += n + 1;
        } else if (vec[i] > 1) sum += tenpower[i];
    }
    printf("%d\n", sum);
    return 0;
}
