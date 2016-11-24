//
//  main.cpp
//  1082
//
//  Created by huangsunyang on 11/24/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>

char unit[4][8]  = {"Shi", "Bai", "Qian", "Wan"};
char one_to_nine[10][8] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void print_four_digit(int n) {
    bool first = true;
    int a = n / 1000;
    n %= 1000;
    int b = n / 100;
    n %= 100;
    int c = n / 10;
    int d = n % 10;
    if (a != 0) {
        printf("%s Qian", one_to_nine[a]);
        first = false;
    }
    if (b != 0) {
        if (!first) {
            putchar(' ');
        } else {
            first = false;
        }
        printf("%s Bai", one_to_nine[b]);
    }
    if (c != 0) {
        if (!first) {
            putchar(' ');
            if (b == 0) {
                printf("ling ");
            }
        } else {
            first = false;
        }
        printf("%s Shi", one_to_nine[c]);
    }
    if (d != 0) {
        if (!first) {
            putchar(' ');
            if (c == 0) {
                printf("ling ");
            }
        } else {
            first = false;
        }
        printf("%s", one_to_nine[d]);
    }
}

int main(int argc, const char * argv[]) {
    int n;
    bool first = true;
    scanf("%d", &n);
    if (n < 0) {
        printf("Fu ");
        n *= -1;
    } else if(n == 0) {
        printf("ling\n");
        return 0;
    }
    if (n >= 100000000) {
        int k = n / 100000000;
        n %= 100000000;
        if (!first) {
            printf(" ");
        } else {
            first = false;
        }
        printf("%s Yi", one_to_nine[k]);
    }
    if (n >= 10000) {
        int k = n / 10000;
        n %= 10000;
        if (!first) {
            putchar(' ');
            
        } else first = false;
        print_four_digit(k);
        printf(" Wan");
    }
    if (n != 0) {
        if (!first) {
            if (n < 1000 )
                printf(" ling");
            putchar(' ');
        } else first = false;
        print_four_digit(n);
    }
    putchar('\n');
    return 0;
}
