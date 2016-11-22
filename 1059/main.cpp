//
//  main.cpp
//  1059
//
//  Created by huangsunyang on 11/21/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;



bool is_prime(long long n, vector<long long> &prime, vector<int> &ct) {
    long long k = (long long)(sqrt(n));
    for (int i = 0; i < prime.size() && prime[i] <= k; i++) {
        if (n % prime[i] == 0) {
            return false;
        }
    }
    prime.push_back(n);
    ct.push_back(0);
    return true;
}

bool is_p(long long n) {
    long long k = (long long)(sqrt(n));
    for (long long i = 2; i <= k; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<long long> prime;
    vector<int> ct;
    long long n;
    scanf("%lld", &n);
    long long k = (long long)(sqrt(n));
//    long long k = n;
    printf("%lld=", n);
    if (is_p(n)) {
        printf("%lld", n);
        return 0;
    }
    for (long long i = 2; i <= k; i++) {
        is_prime(i, prime, ct);
    }
    
    while (n != 1) {
        for (int i = 0; i < prime.size(); i++) {
            if (n % prime[i] == 0) {
                n /= prime[i];
                ct[i]++;
                break;
            }
        }
    }
    //printf("%lu %lu", prime.size(), ct.size());
    bool first = false;
    for (int i = 0; i < ct.size(); i++) {
        if (ct[i] != 0) {
            if (first) {
                printf("*");
            } else {
                first = true;
            }
            printf("%lld", prime[i]);
            if (ct[i] != 1) {
                printf("^%d", ct[i]);
            }
            
        }
    }
    return 0;
}
