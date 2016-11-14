//
//  main.cpp
//  1010
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string.h>
//将字符转为整数
int turn_to_int(char a) {
    if (a >= '0' && a <= '9') {
        return a - '0';
    }
    else return a - 'a' + 10;
}
//将字符串转为radio进制的整数
long long turn(char * a, long long radios) {
    long long sum = 0;
    char * c = a;
    while (*c) {
        sum *= radios;
        sum += turn_to_int(*c);
        c++;
    }
    return sum;
}
//求出字符串中最大的数字以判断至少是几进制
int min_len(char* a) {
    int sum = 0;
    while (*a) {
        if (turn_to_int(*a) > sum) {
            sum = turn_to_int(*a);
        }
        a++;
    }
    return sum + 1;
}
//二分查找
long long binary_search(long long min, long long max, long long target, char * str) {
    while (max >= min) {
        long long middle = (min + max) / 2;
        if (turn(str, middle) == target) {
            return middle;
        }
        else if (turn(str, middle) > target) {
            max = middle - 1;
        }
        else {
            min = middle + 1;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int radia, tag;
    char first[11], second[11];
    scanf("%s %s %d %d", first, second, &tag, &radia);
    long long result;
    if (tag == 1) {
        long long answer;
        result = turn(first, radia);
        int k = min_len(second);        //最小的进制可能 比如56就至少是7进制
        //如果字符串长度就只有1， 所有的进制下它的值不会改变
        if (turn(second, k) < k) {
            if(turn(second, k) == result) answer = k;   //如果恰好就和要求结果一致，则返回k
            else answer = -1;                //如果不一致，但是其值是不变的，所以直接返回不可能
        }
        //如果两个字符串完全一样，则返回给出的进制（需经过前一步的过滤）
        else if(strcmp(first, second) == 0) answer = radia;
        //到了这一步说明该字符串的值是随着进制递增的
        else answer = binary_search(k, 0x0FFFFFFFFFFFF, result, second);
        if (answer != -1) {
            printf("%lld", answer);
            return 0;
        }
    }
    else {
        long long answer;
        result = turn(second, radia);
        int k = min_len(first);
        if (turn(first, k) < k) {
            if(turn(first, k) == result) answer = k;
            else answer = -1;
        }
        else if(strcmp(first, second) == 0) answer = radia;
        else answer = binary_search(k, 0x0FFFFFFFFFFFF, result, first);
    }
    printf("Impossible");
    return 0;
}
