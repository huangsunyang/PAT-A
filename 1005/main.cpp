//
//  main.cpp
//  1005
//
//  Created by huangsunyang on 8/30/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    int sum = 0;
    int ar[100];
    char strings[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char c;
    while ((c = getchar()) != '\n') {
        sum += (c - '0');
    }
    int i = 0;
    while (sum != 0) {
        ar[i] = sum % 10;
        sum /= 10;
        i++;
    }
    if(!i) {
        printf("zero");
        return 0;
    }
    printf("%s", strings[ar[i - 1]]);
    for (int j = i-2; j >= 0; j--) {
        printf(" %s", strings[ar[j]]);
    }
    return 0;
}
