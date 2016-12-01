//
//  main.cpp
//  1068
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
bool matrix[103][10004];
int previous[103][10004];

void napsnack(const vector<int> &coins) {
    for (int i = 0; i < coins.size(); i++) {
        matrix[0][i] = true;;
        previous[0][i] = 1;
    }
    for (int j = 1; j <= m; j++) {
        if (coins[0] == j) {
            matrix[j][0] = true;
            previous[j][0] = 2;
        } else {
            matrix[j][0] = false;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < coins.size(); j++) {
            if (coins[j] > i) {
                //没有选择coins[j]
                matrix[i][j] = matrix[i][j - 1];
                if (matrix[i][j]) {
                    previous[i][j] = 1;
                }
            } else {
                matrix[i][j] = false;
                //没有选择coins[j]
                if (matrix[i][j-1] == true) {
                    matrix[i][j] = true;
                    previous[i][j] += 1;
                }
                //选择了coins[j]
                if (matrix[i-coins[j]][j-1] == true) {
                    matrix[i][j] = true;
                    previous[i][j] += 2;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d", &n, &m);
    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        coins.push_back(temp);
    }
    sort(coins.rbegin(), coins.rend());
    napsnack(coins);
    if (!matrix[m][coins.size() - 1]) {
        printf("No Solution\n");
    } else {
        vector<int> ans;
        int i = m, j = int(coins.size()) - 1;
        while (j >= 0 && i >= 0 && matrix[i][j]) {
            if (previous[i][j] == 3 || previous[i][j] == 2) {
                ans.push_back(coins[j]);
                i -= coins[j];
            }
            j--;
        }
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i++) {
            printf(" %d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
