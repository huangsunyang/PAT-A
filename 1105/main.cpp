//
//  main.cpp
//  1105
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
void get_size(int n, int &row, int &col) {
    for (int i = int(sqrt(n)); i > 0; i--) {
        if (n % i == 0) {
            col = i;
            row = n / i;
            return;
        }
    }
}

void fill(int ** matrix, int st, int t, int row, int col, vector<int> vec) {
    static int count = 0;
    for (int i = t; i < col; i++) {
        matrix[st][i] = vec[count++];
    }
    for (int i = st + 1; i < row; i++) {
        matrix[i][col - 1] = vec[count++];
    }
    for (int i = col - 2; i >= t; i--) {
        matrix[row - 1][i] = vec[count++];
    }
    if(t != col - 1)
    for (int i = row - 2; i > st; i--) {
        matrix[i][t] = vec[count++];
    }
}


int main(int argc, const char * argv[]) {
    int n, temp, row, col;
    vector<int > vec;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    sort(vec.rbegin(), vec.rend());
    get_size(n, row, col);
    int ** matrix = new int * [row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
    }
    int a = row, b = col;
    int s = 0, t = 0;
    while (a - s > 0 && b - t> 0) {
        fill(matrix,s, t, a, b, vec);
        a--, b--, s++, t++;
    }
    for (int i = 0; i < row; i++) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < col; j++) {
            printf(" %d", matrix[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
