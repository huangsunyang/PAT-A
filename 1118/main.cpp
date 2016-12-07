//
//  main.cpp
//  1118
//
//  Created by huangsunyang on 11/6/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_set>
using namespace std;

int ar[10005];

int find_father(int a) {
  if (ar[a] == -1) return a;
  else ar[a] = find_father(ar[a]);
  return ar[a];
}

void merge(int a, int b) {
  int c = find_father(a);
  int d = find_father(b);
  ar[d] = c;
}

int main() {
  for (size_t i = 0; i < 10005; i++) {
    ar[i] = -1;
  }
  int n, q;
  unordered_set<int> st, ed;
  cin >> n;
  for (size_t i = 0; i < n; i++) {
    int temp_num, temp;
    cin >> temp_num;
    int head_bird;
    cin >> head_bird;
    st.insert(head_bird);
    for (size_t j = 1; j < temp_num; j++) {
      cin >> temp;
      st.insert(temp);
      merge(temp, head_bird);
    }
  }
  for (size_t i = 1; i <= st.size(); i++) {
    ed.insert(find_father(i));
  }
  cout << ed.size() << ' '<<st.size()<<endl;
  cin >> q;
  for (size_t i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    printf("%s\n", find_father(a) == find_father(b) ? "Yes" : "No");
  }
  return 0;
}
