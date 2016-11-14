//
//  main.cpp
//  1010
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string.h>
//手动a的n次方
long long mul(long long a, int index) {
    if(index == 0) return 1;
    long long sum = 1;
    while (index--) {
        sum *= a;
    }
    return sum;
}
//将字符转为整数
int turn_to_int(char a) {
    if (a >= '0' && a <= '9') {
        return a - '0';
    }
    else return a - 'a' + 10;
}
//将字符串转为radio进制的整数
long long turn(char * a, long long radios) {
    long long num = 0, sum = 0;
    char * c = a;
    while (*c++) {
        num++;
    }
    for (long long i = num - 1; i >= 0; i--) {
        sum += turn_to_int(a[i]) * mul(radios, int(num - 1 - i));
        if (sum < 0) {
            return -1;
        }
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



int main(int argc, const char * argv[]) {
    int radia, tag;
    char first[11], second[11], temp[11];
    scanf("%s %s %d %d", first, second, &tag, &radia);
    long long result;
    if (tag == 2) {
        strcpy(temp, first);
        strcpy(first, second);
        strcpy(second, temp);
    }
    result = turn(first, radia);
    long long k = min_len(second);
    if (turn(second, k) < k) {
        if (turn(second, k) == result) {
            printf("%lld", k);
            return 0;
        }
        else {
            printf("Impossible");
            return 0;

        }
    }
    long long end = result;
    while (k <= end) {
        long long middle = (k + end) / 2;
        long long temp = turn(second, middle);
//        printf("%lld %lld %lld %lld\n", middle, k, end, temp);
//        printf("%s\n",second);
        if (temp == result) {
            printf("%lld", middle);
            return 0;
        }
        else if(temp > result || temp < 0) end = middle - 1;
        else k = middle + 1;
    }
    printf("Impossible");
    return 0;
}
