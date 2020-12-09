#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> value(n, 1);
        for (int i = 0; i < n-1; ++i) {
            if (ratings[i+1] > ratings[i]) {
                value[i+1] = value[i] + 1;
            }
        }
        for (int i = n-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                value[i] = max(value[i], value[i+1]+1);
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += value[i];
        }
        return sum;
    }
};