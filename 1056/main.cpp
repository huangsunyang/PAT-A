//
//  main.cpp
//  1056
//
//  Created by huangsunyang on 11/29/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct mice {
    int id;
    int weight;
    int rank;
    bool operator < (const mice & b) const{
        return weight < b.weight;
    }
};

int main(int argc, const char * argv[]) {
    int n, m; //每组人数
    scanf("%d %d", &n, &m);
    vector<mice> mices(n);
    vector<mice> game;
    for (int i = 0; i < n; i++) {
        mices[i].id = i;
        scanf("%d", &mices[i].weight);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        game.push_back(mices[temp]);
    }
    vector<mice> next_round;
    while (game.size() != 1) {
        for (int i = 0; i < game.size(); i += m) {
            vector<mice>::iterator pos;
            if (i + m <= game.size()) {
                pos = max_element(game.begin() + i, game.begin() + i + m);
            } else {
                pos = max_element(game.begin() + i, game.end());
            }
            next_round.push_back(*pos);
        }
        int cur_rank = int(next_round.size()) + 1;
        for (int i = 0; i < game.size(); i++) {
            mices[game[i].id].rank = cur_rank;
        }
        std::swap(game, next_round);
        next_round.clear();
    }
    mices[game[0].id].rank = 1;
    printf("%d", mices[0].rank);
    for (int i = 1; i < mices.size(); i++) {
        printf(" %d", mices[i].rank);
    }
    putchar('\n');
    return 0;
}













