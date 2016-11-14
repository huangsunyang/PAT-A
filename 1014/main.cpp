//
//  main.cpp
//  1014
//
//  Created by huangsunyang on 9/15/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct custom {
    int num, time;
    custom(int a, int e): num(a), time(e) {}
};

int go_on(vector<queue<custom> >& vec, queue<custom>& waiting_list, vector<int>& time) {
    int t = 0;
    while (true) {
        int small = 0X0FFFFFFF; //初始值，记录最早能够完成一个人的时间
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].empty()) continue;   //忽略没有人的行？
            small = small < vec[i].front().time ? small : vec[i].front().time; //找到其中最快的时间
        }
        if (small == 0X0FFFFFFF) break;  //如果所有队伍都是空的或者超时，就结束循环
        t += small;     //累计时间
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].empty()) continue; //忽略没有人的行？
            vec[i].front().time -= small;   //经过了small分钟后，第一个人剩余时间减少
            if (vec[i].front().time == 0) {     //如果时间到了，就出队
                time[vec[i].front().num] = t;
                vec[i].pop();
                if (t >= 540) {
                    while (!vec[i].empty()) {
                        vec[i].pop();
                    }
                }
                if (!waiting_list.empty() && t < 540) {    //如果候选队列中还有人且时间还没到5点，就进队
                    vec[i].push(waiting_list.front());
                    waiting_list.pop();
                }
            }
        }
    }
    return t;
}
//打印时间
void time_print(int a) {
    int hour = 8 + a / 60;  //小时数
    int minute = a % 60;    //分钟数
    if (a == -1) {
        printf("Sorry\n");
    } else printf("%02d:%02d\n", hour, minute);
}

int main(int argc, const char * argv[]) {
    int n, m, k, q, t;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vector<int> final_time(k + 1);
    vector<queue<custom> > qe(n);
    queue<custom> waiting_list;
    int start_i = 0;
    for (int i = 0; i < final_time.size(); i++) {
        final_time[i] = -1;
    }
    for (int i = 1; i <= k  && i <= n * m; i++) {
        scanf("%d", &t);
        qe[start_i++ % n].push(custom(i,t));
    }
    for (int i = n * m + 1; i <= k; i++) {
        scanf("%d", &t);
        waiting_list.push(custom(i,t));
    }
    go_on(qe, waiting_list, final_time);
    for (int i = 0; i < q; i++) {
        scanf("%d", &t);
        time_print(final_time[t]);
    }
    return 0;
}

