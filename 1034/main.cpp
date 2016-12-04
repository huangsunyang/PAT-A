//
//  main.cpp
//  1034
//
//  Created by huangsunyang on 12/4/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <fstream>
using namespace std;

int st = 0, thre;

struct phone {
    string a;
    string b;
    int time;
};

int dist[2005][2005];
bool has_found[2005];
string names[2005];

pair<int, int> breath_first_search(int root) {
    queue<int> que;
    que.push(root);
    int total = 0;
    int temp_time[2002];
    for (int i = 0; i < st; i++) {
        temp_time[i] = 0;
    }
    while (!que.empty()) {
        while (!que.empty() && has_found[que.front()]) {
            que.pop();
        }
        if (que.empty()) break;
        int cur = que.front();
        has_found[cur] = true;
        que.pop();
        for (int i = 0; i < st; i++) {
            if (dist[cur][i] != 0 ) {
                if (!has_found[i]) {
                    temp_time[cur] += dist[cur][i];
                    temp_time[i] += dist[cur][i];
                    total += dist[cur][i];
                    que.push(i);
                }
            }
            if (dist[i][cur] != 0) {
                if (!has_found[i]) {
                    temp_time[cur] += dist[i][cur];
                    temp_time[i] += dist[i][cur];
                    total += dist[i][cur];
                    que.push(i);
                }
            }
        }
    }
    int max = -1, ret = -1, num = 0;
    if (total > thre) {
        for (int i = 0; i < st; i++) {
            if (temp_time[i] > max) {
                max = temp_time[i];
                ret = i;
            }
            if (temp_time[i] > 0) num++;
        }
    }
    return make_pair(ret, num);
}

struct answer {
    int i, num;
};

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return names[a.first] < names[b.first];
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n>>thre;
    vector<phone> phones;
    vector<pair<int, int>> vec;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        phone temp;
        cin>>temp.a>>temp.b>>temp.time;
        if(mp.find(temp.a) == mp.end()) mp[temp.a] = st++;
        if(mp.find(temp.b) == mp.end()) mp[temp.b] = st++;
        phones.push_back(temp);
    }
    int test = 0;
    for (int i = 0; i < n; i++) {
        dist[mp[phones[i].a]][mp[phones[i].b]] += phones[i].time;
        if (phones[i].a == "Q" || phones[i].b == "Q" ) {
            test+=phones[i].time;
        }
    }
    for (map<string, int>::iterator i = mp.begin(); i != mp.end(); i++) {
        names[i->second] = i->first;
    }
    for (int i = 0; i < st; i++) {
        if (has_found[i]) {
            continue;
        }
        pair<int, int> k = breath_first_search(i);
        if (k.first >= 0 && k.second > 2) {
            vec.push_back(k);
        }
    }
    sort(vec.begin(), vec.end(), compare);
    printf("%d\n", int(vec.size()));
    for (int i = 0; i < vec.size(); i++) {
        cout<<names[vec[i].first]<<" "<<vec[i].second<<endl;
    }
    return 0;
}
