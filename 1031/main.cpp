//
//  main.cpp
//  1031
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
void print_blank(int n) {
    while (n--) {
        putchar(' ');
    }
}
int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int k = int(s.size() + 2) / 3;
    int n2 = int(s.size()) - 2 * k + 2;
    int i;
    for (i = 0; i < k - 1; i++) {
        putchar(s[i]);
        print_blank(n2 - 2);
        putchar(s[s.size() - 1 - i]);
        putchar('\n');
    }
    cout<<s.substr(i, n2)<<endl;
    return 0;
}
