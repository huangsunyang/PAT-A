//
//  main.cpp
//  1013-2
//
//  Created by huangsunyang on 9/14/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void initial(vector<int>& flag) {
    for (int i = 0; i < flag.size(); i++) {
        flag[i] = 0;
    }
}
void try_out(int a, vector<vector<int> >& vec, vector<int>& flag, vector<int>& has_found, int b) {
    if (has_found[a]) {
        return;
    }
    has_found[a] = 1;
    for (int i = 0; i < vec[a].size(); i++) {
        if (has_found[vec[a][i]] || vec[a][i] == b) {
            continue;
        }
        flag[vec[a][i]] = flag[a];
        try_out(vec[a][i], vec, flag, has_found, b);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, k, a, b, start;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int> > vec(n);
    vector<int> flag(n), has_found(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        vec[a-1].push_back(b-1);
        vec[b-1].push_back(a-1);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &a);
        start = 0;
        initial(flag);
        initial(has_found);
        for (int i = 0; i < n; i++) {
            if (i == a - 1) continue;
            if (flag[i] == 0) flag[i] = ++start;
            try_out(i, vec, flag, has_found, a - 1);
        }
        printf("%d\n", start - 1);
    }
    return 0;
}
