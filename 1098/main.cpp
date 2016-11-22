//
//  main.cpp
//  1098
//
//  Created by huangsunyang on 11/22/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insertion_next(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            int j = i - 1;
            while (j >= 0 && vec[j] > vec[j + 1]) {
                std::swap(vec[j + 1], vec[j]);
                j--;
            }
            break;
        }
    }
}

void maintain(vector<int> & vec, int n) {
    int rt = 0;
    int change = rt;
    while(1) {
        int cur_max = vec[rt];
        if (rt * 2 + 1 < n && vec[2 * rt + 1] > cur_max) {
            change = rt * 2 + 1;
            cur_max = vec[change];
        }
        if (rt * 2 + 2 < n && vec[2 * rt + 2] > cur_max) {
            change = rt * 2 + 2;
            cur_max = vec[change];
        }
        if (change == rt) {
            break;
        } else {
            std::swap(vec[rt], vec[change]);
            rt = change;
        }
    }
}

void heap_sort_next(vector<int> & vec) {
    int i;
    for (i = int(vec.size() - 1); i >= 0; i--) {
        if (vec[i] < vec[0]) {
            std::swap(vec[i], vec[0]);
            break;
        }
    }
    maintain(vec, i);
}

void print(vector<int> vec) {
    printf("%d", vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        printf(" %d", vec[i]);
    }
    putchar('\n');
}

bool is_insertion_sort(vector<int> & origin, const vector<int> & after) {
    int i;
    for (i = 1; i < after.size(); i++) {
        if (after[i] < after[i - 1]) {
            break;
        }
    }
    sort(origin.begin(), origin.begin() + i);
    return equal(origin.begin(), origin.end(), after.begin());
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> origin, after;
    int n, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        origin.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        after.push_back(temp);
    }
    if (is_insertion_sort(origin, after)) {
        printf("Insertion Sort\n");
        insertion_next(after);
        print(after);
    } else {
        printf("Heap Sort\n");
        heap_sort_next(after);
        print(after);
    }
    return 0;
}
