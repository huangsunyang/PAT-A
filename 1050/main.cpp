//
//  main.cpp
//  1050
//
//  Created by huangsunyang on 12/1/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
bool appeared[128];

int main(int argc, const char * argv[]) {
    // insert code here...
    char * a = NULL, * b = NULL;
    size_t len_a, len_b;
    getline(&a, &len_a, stdin);
    getline(&b, &len_b, stdin);
    for (char * c = b; *c != '\n'; c++) {
        appeared[*c] = true;
    }
    for (char * c = a; *c != '\n'; c++) {
        if (!appeared[*c]) {
            putchar(*c);
        }
    }
    return 0;
}
