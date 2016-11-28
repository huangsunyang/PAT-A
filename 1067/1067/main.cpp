//
//  main.cpp
//  1067
//
//  Created by huangsunyang on 11/27/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<int> vec;
    scanf("%d", &n);
    vector<bool> has_found(n, false);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        pos[temp] = i;
    }
    int fin = 0;
    int num = 0;
    for (int i = 0; i < pos.size(); i++) {
        if (has_found[i] || pos[i] == i) {
            continue;
        } else {
            fin++;
            has_found[i] = true;
            int temp = 1;
            int k = pos[i];
            while (k != i) {
                has_found[k] = true;
                k = pos[k];
                temp++;
            }
            num += temp;
        }
    }
    if (pos[0] == 0) {
        num += 2;
    }
    printf("%d\n", num + fin - 2 > 0 ? num + fin - 2 : 0 );
    return 0;
}
