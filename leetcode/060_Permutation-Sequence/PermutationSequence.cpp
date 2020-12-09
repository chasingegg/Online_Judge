#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    int cal(int n) {
        int res = 1;
        for (int i = 1; i <= 9; ++i) {
            res *= i;
            if (res >= n) return i;
        }
        return 0;
    }

    string getPermutation(int n, int k) {
        int x = cal(k);
        string res = "";
        for (int i = 1; i <= n; ++i) {
            res += to_string(i);
        }
        return permutate(n-x, res, k);
    }   

    string permutate(int idx, string res, int &count) {
        if (count == 0) return res;
        if (idx == res.size()-1) --count;
        for (int i = idx; i < res.size(); ++i) {
            string tmp = res;
            char tt = res[i];
            for (int j = i-1; j >= idx; --j) {
                res[j+1] = res[j];
            }
            res[idx] = tt;
            string r = permutate(idx+1, res, count);
            if (r != "") return r;
            res = tmp;        
        }
        return "";
    }
};