#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(int &t1, int &t2) {
        int tmp = t1;
        t1 = t2;
        t2 = tmp;
    }

    void per(int toSwap, vector<int> num, vector<vector<int>> &res) {
        if (toSwap == num.size()-1) {
            res.push_back(num);
        } else {
            for (int i = toSwap; i < num.size(); ++i) {
                swap(num[toSwap], num[i]);
                per(toSwap+1, num, res);
                swap(num[toSwap], num[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n <= 0) return res;
        per(0, nums, res);
        return res;
    }
};