//
//  main.cpp
//  1013
//
//  Created by huangsunyang on 9/14/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, k, a, b, start;
    scanf("%d %d %d", &n, &m, &k);
    int** ar = new int* [n];
    int* flag = new int[n];
    for (int i = 0; i < n; i++) {
        ar[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ar[a - 1][b - 1] = 1;
        ar[b - 1][a - 1] = 1;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        start = 0;
        for (int i = 0; i < n; i++) {
            flag[i] = 0;
        }
        for (int j = 0; j < n; j++) {
            if (j == a - 1) continue;
            if (flag[j] == 0) {
                int q;
                for (q = j; q < n; q++) {
                    if (ar[j][q] != 0 && flag[q] != 0) {
                        flag[j] = flag[q];
                        break;
                    }
                }
                if (q == n)
                    flag[j] = ++start;
            }
            for (int l = j; l < n; l++) {
                if (l == a - 1 || ar[j][l] == 0) continue;
                flag[l] = flag[j];
            }
        }
        printf("%d\n", start - 1 < 0 ? 0 : start - 1);
    }
    return 0;
}
