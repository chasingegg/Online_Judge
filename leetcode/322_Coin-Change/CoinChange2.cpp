#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    void nextStage(vector<int>&coins, queue<int> &bfs, vector<bool> &mark, bool &find) {
        int n = bfs.size();
        for (int i = 0; i < n; ++i) {
            int amount = bfs.front();
            bfs.pop();
            for (auto coin : coins) {
                if (amount == coin) {
                    find = true;
                    return;
                }
                if (amount > coin && !mark[amount-coin]) {
                    bfs.push(amount-coin);
                    mark[amount-coin] = true;
                }
            }
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> bfs;
        vector<bool> mark(amount+1, false);
        bfs.push(amount);
        bool find = false;
        int res = 0;
        while (!bfs.empty()) {
            nextStage(coins, bfs, mark, find);
            res++;
            if (find) return res;
        }
        return -1;
    }
};