#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        int res = 0;
        long a = 0;
        long b = 0;
        // 把数分成两半 比如2501，分成2501和0，250和1，25和1，2和501
        for (long m = 1; m <= n; m *= 10) {
            a = n / m;
            b = n % m;
            if (a % 10 > 1) {
                res += a / 10 * m + m;
            } else if (a % 10 == 1) {
                res += a / 10 * m + b + 1;
            } else {
                res += a / 10 * m;
            }
        }
        return res;
    }
};