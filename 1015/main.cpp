//
//  main.cpp
//  1015
//
//  Created by huangsunyang on 9/15/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int trans_to_demical(int num, int radix) {
    string a;
    while (num != 0) {
        a.push_back(num % radix + '0');
        num /= radix;
    }
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum = sum * radix + (a[i] - '0');
    }
    return sum;
}
bool is_prime(int a) {
    if (a == 1) {
        return false;
    }
    int end = int(sqrt(a));
    for (int i = 2; i <= end; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, radix;
    while (scanf("%d", &n) && n >= 0) {
        scanf("%d", &radix);
        //printf("%d %d\n", n, trans_to_demical(n, radix));
        if (is_prime(n) && is_prime(trans_to_demical(n, radix))) {
            printf("Yes\n");
        } else printf("No\n");
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
