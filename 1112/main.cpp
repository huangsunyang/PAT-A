//
//  main.cpp
//  1112
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
void trans(char * ch, int n) {
    char * temp;
    int ar[200];
    for (int i = 0; i < 200; i++) {
        ar[i] = -1;
    }
    for (temp = ch; *temp != '\0';) {
        char *  j;
        for (j = temp + 1; j < temp + n && *j != '\0'; j++) {
            if (*j != *(j - 1) || *j == '\0') {
                ar[*temp] = 0;
                break;
            }
        }
        if(j == temp + n) {
            if(ar[*temp])
                ar[*temp] = 1;
        }
        temp = j;
    }
    
    bool not_print[200];
    for (int i = 0; i < 200; i++) {
        not_print[i] = true;
    }
    
    for (temp = ch; *temp != '\0'; ) {
        if (ar[*temp] == 1) {
            if(not_print[*temp]) {
                putchar(*temp);
                not_print[*temp] = false;
            }
            temp += n;
        } else {
            temp ++;
        }
    }
    putchar('\n');
    for (temp = ch; *temp != '\0'; ) {
        putchar(*temp);
        if (ar[*temp] == 1) {
            temp += n;
        } else {
            temp ++;
        }
    }
    putchar('\n');
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char ch[1200];
    int n;
    scanf("%d %s", &n, ch);
    trans(ch, n);
    return 0;
}
