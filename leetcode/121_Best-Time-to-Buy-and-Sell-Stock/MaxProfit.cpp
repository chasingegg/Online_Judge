#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int cur = prices[0]; 
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] - cur > res) {
                res = prices[i] - cur;
            }
            if (cur > prices[i]) {
                cur = prices[i];
            }
        }
        return res;
    }
};