#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;
        int cooldown = 0;
        int bought = -prices[0];
        int sold = 0;
        for (int i = 1; i < n; ++i) {
            bought = max(bought, cooldown-prices[i]);
            cooldown = max(cooldown, sold);
            sold = bought + prices[i];
        }
        return max(cooldown, sold);
    }
};