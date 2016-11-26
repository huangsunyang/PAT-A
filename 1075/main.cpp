//
//  main.cpp
//  1075
//
//  Created by huangsunyang on 11/26/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int users[100001][6];
int total_score[6];

struct user {
    int id;
    int total;
    int number;
    int fail;
    int rank;
};

bool compare(const user & a, const user & b) {
    if (a.total > b.total) {
        return true;
    } else if (a.total == b.total) {
        if (a.number > b.number) {
            return true;
        } else if(a.number == b.number) {
            if (a.id < b.id) {
                return true;
            }
        }
    }
    return false;
}

void print_rank(vector<user> & rank, int i, int k) {
    printf("%d %05d %d", rank[i].rank, rank[i].id, rank[i].total);
    for (int j = 1; j <= k; j++) {
        if (users[rank[i].id][j] >= 0) {
            printf(" %d", users[rank[i].id][j]);
        } else printf(" -");
    }
    putchar('\n');
}

int main(int argc, const char * argv[]) {
    int n, k, m;
    vector<user> rank;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            users[i][j] = -2;
        }
    }
    for (int i = 1; i <= k; i++) {
        scanf("%d", &total_score[i]);
    }
    for (int i = 0; i < m; i++) {
        int id, pro_num, score;
        scanf("%d %d %d", &id, &pro_num, &score);
        users[id][pro_num] = std::max(users[id][pro_num], score);
    }
    for (int i = 1; i <= n; i++) {
        user temp;
        temp.number = temp.fail = temp.total = 0;
        temp.id = i;
        for (int j = 1; j <= k; j++) {
            if (users[i][j] == total_score[j]) {
                temp.number++;
                temp.total += users[i][j];
            } else if(users[i][j] < 0) {
                temp.fail++;
                if (users[i][j] == -1) {
                    users[i][j] = 0;
                }
            } else {
                temp.total += users[i][j];
            }
        }
        if (temp.fail != k) {
            rank.push_back(temp);
        }
    }
    sort(rank.begin(), rank.end(), compare);
    rank[0].rank = 1;
    for (int i = 1; i < rank.size(); i++) {
        if (rank[i].total == rank[i-1].total) {
            rank[i].rank = rank[i-1].rank;
        } else rank[i].rank = i + 1;
    }
    for (int i = 0; i < rank.size(); i++) {
        print_rank(rank, i, k);
    }
    return 0;
}
