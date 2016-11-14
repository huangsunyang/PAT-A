//
//  main.cpp
//  1023
//
//  Created by huangsunyang on 10/11/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool is_only(vector<int> a, vector<int> b) {
    int p[10], q[10];
    for (int i = 0; i < 10; i++) {
        p[i] = q[i] = 0;
    }
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        p[a[i]]++;
        q[b[i]]++;
    }
    for (int i = 0; i < 10; i++) {
        if (p[i] != q[i]) {
            return false;
        }
    }
    return true;
}
vector<int> doub(vector<int> a) {
    vector<int> b;
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        int k = flag + 2 * a[i];
        b.push_back(k % 10);
        flag = k / 10;
    }
    if(flag == 1) b.push_back(1);
    return b;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string temp;
    cin>>temp;
    vector<int> a, b;
    for (int i = int(temp.size()) - 1; i >= 0; i--) {
        a.push_back(temp[i] - '0');
    }
    b = doub(a);
    if (is_only(a, b)) {
        printf("Yes\n");
    } else printf("No\n");
    for (int i = int(b.size()) - 1; i > -1; i--) {
        printf("%d", b[i]);
    }
    return 0;
}
