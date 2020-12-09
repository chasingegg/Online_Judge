#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int x = prices[0];
        int res = 0;
        for (int i = 1; i < n; ++i) { 
            if (prices[i] > prices[i-1]) {
                if (i== n-1) {
                    res += prices[i] - x;
                } else
                continue;
            }
            else {
                res += prices[i-1] - x;
                x = prices[i];
            }
        }
        return res;
    }
};