//
//  main.cpp
//  1093
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    char str[100000];
    vector<int> p, t;
    scanf("%s", str);
    char * ptr = str;
    int num_p = 0, num_t = 0;
    for (; *ptr != '\0'; ptr++) {
        if (*ptr == 'P') {
            num_p++;
        } else if (*ptr == 'T') {
            num_t++;
        } else {
            p.push_back(num_p);
            t.push_back(num_t);
        }
    }
    int fin = 0;
    for (int i = 0; i < p.size(); i++) {
        fin += p[i] * (num_t - t[i]);
        fin %= 1000000007;
    }
    printf("%d\n", fin);
    return 0;
}
