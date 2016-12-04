//
//  main.cpp
//  1041
//
//  Created by huangsunyang on 12/4/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int found[10005];

int main(int argc, const char * argv[]) {
    vector<int> vec;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        vec.push_back(temp);
        found[temp]++;
    }
    bool win = false;;
    for (int i = 0; i < n; i++) {
        if (found[vec[i]] == 1) {
            printf("%d\n", vec[i]);
            win = true;
            break;
        }
    }
    if (!win) {
        printf("None\n");
    }
    return 0;
}
