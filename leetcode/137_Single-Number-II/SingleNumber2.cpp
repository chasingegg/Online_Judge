#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto &num : nums) {
            b = (b ^ num) & ~a;
            a = (a ^ num) & ~b;
        }
        return a | b;
    }

    int singleNumber2(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (auto &num : nums) {
                sum += (num >> i) & 1;
            }
            sum %= 3;
            // cout << sum << endl;
            if (sum != 0)
                res += (sum << i);
        }
        return res;
    }
};