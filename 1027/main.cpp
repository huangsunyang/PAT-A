//
//  main.cpp
//  1027
//
//  Created by huangsunyang on 10/28/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
void transfer(int a) {
    char ch[13] = {'0','1','2','3','4','5','6','7','8','9', 'A', 'B', 'C'};
    string s = "";
    while (a != 0) {
        s += ch[a % 13];
        a /= 13;
    }
    if(s.size() == 0) s += '0';
    if(s.size() == 1) s += '0';
    printf("%c%c", s[1], s[0]);
}



int main(int argc, const char * argv[]) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("#");
    transfer(a);
    transfer(b);
    transfer(c);
    return 0;
}
