//
//  main.cpp
//  1012
//
//  Created by huangsunyang on 9/13/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int highest(int a, int b, int c, int d, int * e) {
    int aa = a < b ? a : b;
    int bb = c < d ? c : d;
    int sum = aa < bb ? aa : bb;
    *e = sum;
    if (sum == a) return 0;
    else if(sum == b) return 1;
    else if(sum == c) return 2;
    else return 3;
}
class student {
public:
    int id = 0, Q = 0;
    student(int d, int c):id(d), Q(c){}
    bool operator < (student m) const {
        return Q > m.Q;
    }
};
int findme(vector<student> vec, int d) {
    int k = -1;
    for (int i = 0; i < vec.size(); i++)
        if (vec[i].id == d) {
            k = i;
            break;
        }
    while (k >= 1 && vec[k].Q == vec[k-1].Q) k--;
    if (k >= 0) return k;
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, id, C, M, E;
    const char SUBJECT[4] = {'A', 'C', 'M', 'E'};
    vector<student> mat, eng, aver, comp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &id, &C, &M, &E);
        comp.push_back(student(id, C));
        eng.push_back(student(id, E));
        aver.push_back(student(id, C + E + M));
        mat.push_back(student(id, M));
    }
    sort(comp.begin(), comp.end());
    sort(eng.begin(), eng.end());
    sort(aver.begin(), aver.end());
    sort(mat.begin(), mat.end());
    for (int i = 0; i < m; i++) {
        scanf("%d", &id);
        int a = findme(aver, id);
        int b = findme(comp, id);
        int c = findme(mat, id);
        int d = findme(eng, id);
        if (a == -1) printf("N/A\n");
        else {
            int e, x = highest(a, b, c, d, &e);
            printf("%d %c\n", e + 1, SUBJECT[x]);
        }
    }
    return 0;
}
