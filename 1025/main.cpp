//
//  main.cpp
//  1025
//
//  Created by huangsunyang on 10/16/2016.
//  Copyright © 2016年 huangsunyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct testee {
    std::string num;
    int local_rank;
    int location;
    int final_rank;
    int score;
    testee(std::string name, int loc, int sco): num(name), location(loc), score(sco){}
    void print() {
        printf("%s %d %d %d\n", num.c_str(), final_rank, location, local_rank);
    }
    bool operator > (const testee & t) const {
        return score > t.score || (score == t.score && num < t.num);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<testee> final_vec, local_vec;
    int n, m, temp_score;
    std::string s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        local_vec.clear();
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            std::cin>>s;
            scanf("%d", &temp_score);
            local_vec.push_back(testee(s, i, temp_score));
        }
        std::sort(local_vec.begin(), local_vec.end(), std::greater<testee>());
        for (int k = 0; k < m; k++) {
            local_vec[k].local_rank = k + 1;
            if (k > 0 && local_vec[k].score == local_vec[k-1].score) {
                local_vec[k].local_rank = local_vec[k-1].local_rank;
            }
            final_vec.push_back(local_vec[k]);
        }
    }
    std::sort(final_vec.begin(), final_vec.end(), std::greater<testee>());
    printf("%u\n", unsigned(final_vec.size()));
    for (int i = 0; i < final_vec.size(); i++) {
        final_vec[i].final_rank = i + 1;
        if (i > 0 && final_vec[i].score == final_vec[i-1].score) {
            final_vec[i].final_rank = final_vec[i-1].final_rank;
        }
        final_vec[i].print();
    }
    return 0;
}
