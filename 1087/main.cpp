//
//  main.cpp
//  1087
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
using namespace std;
struct node {
    char name[5];
    int happy;
    int cur_dis = 0x7FFFFFFF;
    int total_hp = 0;
    int pre = -1;
    int way_num = 0;
};

node city[200];
bool has_found[200];
int dis[200][200];

struct compare {
    bool operator () (int a, int b) {
        return city[a].cur_dis > city[b].cur_dis;
    }
};

int main(int argc, const char * argv[]) {
    int n, m, st, ed, temp_len;
    map<string, int> mp;
    char st_name[5], t1[5], t2[5];
    scanf("%d %d %s", &n, &m, st_name);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dis[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++) {
        scanf("%s %d", city[i].name, &city[i].happy);
        mp[string(city[i].name)] = i;
    }
    strcpy(city[0].name, st_name);
    mp[string(st_name)] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s %s %d", t1, t2, &temp_len);
        int a = mp[string(t1)], b = mp[string(t2)];
        dis[a][b] = temp_len;
        dis[b][a] = temp_len;
    }
    st = mp[string(st_name)];
    ed = mp[string("ROM")];
    priority_queue<int, vector<int>, compare> que;
    city[st].cur_dis = 0;
    city[st].way_num = 1;
    que.push(st);
    for (int i = 0; i < n - 1; i++) {
        while (has_found[que.top()]) {
            que.pop();
        }
        int cpt = que.top();
        has_found[cpt] = true;
        que.pop();
        for (int j = 0; j < n; j++) {
            if (dis[cpt][j] == -1 || has_found[j]) {
                continue;
            }
            if (city[j].cur_dis > city[cpt].cur_dis + dis[cpt][j]) {
                city[j].cur_dis = city[cpt].cur_dis + dis[cpt][j];
                city[j].pre = cpt;
                city[j].total_hp = city[cpt].total_hp + city[j].happy;
                city[j].way_num = city[cpt].way_num;
                que.push(j);
            } else if(city[j].cur_dis == city[cpt].cur_dis + dis[cpt][j]) {
                city[j].way_num += city[cpt].way_num;
                if (city[j].total_hp < city[cpt].total_hp + city[j].happy) {
                    city[j].pre = cpt;
                    city[j].total_hp = city[cpt].total_hp + city[j].happy;
                    que.push(j);
                }
            }
        }
    }
    int t = ed;
    vector<int> way;
    while (t != -1) {
        way.push_back(t);
        t = city[t].pre;
    }
    printf("%d %d %d %d\n", city[ed].way_num, city[ed].cur_dis, city[ed].total_hp,
           city[ed].total_hp / int(way.size() - 1));
    printf("%s", city[way.back()].name);
    for (vector<int>::reverse_iterator i = way.rbegin() + 1; i != way.rend(); i++) {
        printf("->%s", city[*i].name);
    }
    putchar('\n');
    return 0;
}













