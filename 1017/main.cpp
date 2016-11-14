//
//  main.cpp
//  1017
//
//  Created by huangsunyang on 9/20/2016.
//  Copyright © 2016 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
using namespace std;
class custom {
public:
    int hour = 25, minute, second, need_time, real_time = 0x0FFFFFFF, real_end_time = 0x0FFFFFFF;
    int wait_time = 0;
    bool arrive_before_8 = false;
    custom() {}
    custom(int hou, int minut, int secon, int need_tim) {
        this->hour = hou;
        this->minute = minut;
        this->second = secon;
        this->need_time = need_tim < 60 ? need_tim : 60;
        this->real_time = this->hour * 60 * 60 + this->minute * 60 + this->second;
        this->real_end_time = this->real_time + this->need_time * 60;
    }
    
};
struct compare {
    bool operator () (const custom& b, const custom& a) {
        return b.real_time < a.real_time;
    }
};
bool compare_end(custom a, custom b) {
    return a.real_end_time < b.real_end_time;
}
struct comp {
    bool operator() (custom& a, custom& b) {
        return a.real_end_time > b.real_end_time;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, k, hour, min, sec, need, all_time = 0;
    char a, b;
    scanf("%d %d", &n, &k);
    vector<custom> que;
    priority_queue<custom, vector<custom>, comp> win;
    int i;
    //接受所有人，全部加入队伍
    for (i = 0; i < n; i++) {
        scanf("%d %c %d %c %d %d", &hour, &a, &min, &b, &sec, &need);
        que.push_back(custom(hour, min, sec, need));
    }
    //队伍按照到达顺序排队
    sort(que.begin(), que.end(), compare());
    //将5点以后来的人踢出队伍
    for (int i = int(que.size() - 1); i >= 0; i--) {
        if (que[i].real_end_time > 17 * 3600) {
            que.pop_back();
            n--;
        }
    }
    //将前k个人进入窗口，其等待时间为0或者为8：00 - 到达时间
    for (i = 0; i < k && i < n; i++) {
        if (8 * 3600 > que[i].real_time) {
            all_time += 3600 * 8 - que[i].real_time;
            que[i].real_end_time += 3600 * 8 - que[i].real_time;
        }
        win.push(que[i]);
    }
    while (i < n) {
        //window中的第一个人明显是最早离开的，将队列中的到达时间与其离开时间比较，得出等待时间
        int wait = que[i].real_time >= win.top().real_end_time ?
        0 : win.top().real_end_time - que[i].real_time;
        all_time += wait;
        que[i].real_time += wait;
        que[i].real_end_time += wait;
        win.pop();
        win.push(que[i++]);
    }
    if (n == 0) {
        printf("0.0\n");
    }
    else printf("%.1lf\n", all_time / 60.0 / n);
    return 0;
}
