//
//  main.cpp
//  1024
//
//  Created by huangsunyang on 10/13/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
std::vector<int> add(std::vector<int> a, std::vector<int> b) {
    int flag = 0, i;
    std::vector<int> c;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        int k = a[i] + b[i] + flag;
        c.push_back(k % 10);
        flag = k/10;
    }
    if (i < a.size()) {
        for (; i < a.size(); i++) {
            int k = a[i] + flag;
            c.push_back(k % 10);
            flag = k/10;
        }
    } else if (i < b.size()) {
        for (; i < b.size(); i++) {
            int k = b[i] + flag;
            c.push_back(k % 10);
            flag = k/10;
        }
    }
    if (flag == 1) {
        c.push_back(1);
    }
    return c;
}
std::vector<int> reverse(std::vector<int> a) {
    int k = int(a.size()) - 1;
    for (int i = 0; i < a.size() / 2; i++) {
        int o = a[i];
        a[i] = a[k - i];
        a[k-i] = o;
    }
    return a;
}

std::vector<int> dou(std::vector<int> a) {
    return add(a, reverse(a));
}

bool isparlinom(std::vector<int> a) {
    int k = int(a.size()) - 1;
    for (int i = 0; i < a.size() / 2; i++) {
        if (a[i] != a[k - i]) {
            return false;
        }
    }
    return true;
}
void print(std::vector<int> a) {
    for (int i = int(a.size()) - 1; i > -1; i--) {
        printf("%d", a[i]);
    }
}
bool get_vector(std::vector<int> & a) {
    char c;
    while ((c = getchar()) != ' ') {
        a.push_back(c - '0');
    }
    a = reverse(a);
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> a;
    int n;
    bool has_found = false;
    get_vector(a);
    scanf("%d", &n);
    if (isparlinom(a)) {
        print(a);
        putchar('\n');
        printf("0\n");
        has_found = true;
        n = 0;
    }
    for (int i = 1; i <= n; i++) {
        a = dou(a);
        if (isparlinom(a)) {
            print(a);
            putchar('\n');
            printf("%d\n", i);
            has_found = true;
            break;
        }
    }
    if (!has_found) {
        print(a);
        putchar('\n');
        printf("%d\n", n);
    }
    return 0;
}
