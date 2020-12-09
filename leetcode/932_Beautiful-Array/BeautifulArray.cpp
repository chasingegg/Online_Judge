#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int> &res, int &idx, int N, int a, int d) {
        if (N == 1) {
            res[idx++] = a;
        } else if (N == 2) {
            res[idx++] = a;
            res[idx++] = a + d;
        } else {
            solve(res, idx, (N+1)/2, a, 2*d);
            for (int i = 0; i < (N+1)/2; ++i) {
                if (res[i] + d <= a + (N-1) * d)
                    res[idx++] = res[i] + d;
            }
        }
    }
    vector<int> beautifulArray(int N) {
        vector<int> res(N);
        int idx = 0;
        solve(res, idx, N, 1, 1);
        return res;
    }
};