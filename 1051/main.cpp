//
//  main.cpp
//  1051
//
//  Created by huangsunyang on 11/30/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    int max_size, n, q;
    scanf("%d %d %d", &max_size, &n, &q);
    for (int i = 0; i < q; i++) {
        stack<int> st;
        int temp_count = 1;
        bool stack = true;
        for (int i = 1; i <= n; i++) {
            int temp;
            scanf("%d", &temp);
            while (st.empty() || st.top() != temp) {
                st.push(temp_count++);
                if (st.size() > max_size) {
                    stack = false;
                    break;
                }
            }
            st.pop();
        }
        if (!stack) {
            printf("NO\n");
        }
        else printf("YES\n");
    }
    return 0;
}
