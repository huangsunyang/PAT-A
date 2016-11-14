//
//  main.cpp
//  1100
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;
char one[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char two[13][5] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char all[26][5] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int quest(char * temp, int & flag) {
    int sum = 0;
    if(temp[0] >= '0' && temp[0] <= '9') {
        while (*temp != '\n') {
            sum = sum * 10 + *temp - '0';
            temp++;
        }
        return sum;
    }
    else {
        int i, j = 0;
        for (i = 0; temp[i] != '\0'; i++) {
            if(temp[i] == ' ') {
                j = i + 1;
                temp[i] = '\0';
            }
            if(temp[i] == '\n') {
                temp[i] = '\0';
            }
        }
        char * temp2 = temp + j;
        int a = 0, b = 0;
        for (int i = 0; i < 26; i++) {
            if (strcmp(temp, all[i]) == 0) {
                a = i;
            }
            if (strcmp(temp2, all[i]) == 0) {
                b = i;
            }
        }
        flag = 1;
        if (j == 0) {
            return a > 12 ? (a - 12) * 13 : a;
        } else return 13 * (a - 12) + b;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        int flag = 0;
        char temp[20];
        fgets(temp, 20, stdin);
        int a = quest(temp, flag);
        if (flag == 1) {
            printf("%d\n", a);
        } else {
            //printf("%d\n", a);
            if(a == 0) {
                printf("%s\n", "tret");
            }
            else if(a < 13) {
                printf("%s\n", one[a]);
            } else if(a % 13 == 0) {
                printf("%s\n", two[a / 13]);
            } else {
                printf("%s %s\n", two[a / 13], one[a % 13]);
            }
        }
    }
    
    return 0;
}
