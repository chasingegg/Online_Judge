#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        int step = 0;
        // greedy algorithm
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0) {
                n /= i;
                step += i;
                --i;
            }
        }
        return step;
    }
};