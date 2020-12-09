#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) return true;
        int n = num % 10;
        if (n == 2 || n == 3 || n == 7 || n == 8) return false;
        int l = 1; 
        int r = num;
        while (l <= r) {
            int cur = l + (r -l)/2;
            long cc = (long)cur * cur;
            if (cc == num) return true;
            if (cc > num) {
                r = cur - 1;
            } else {
                l = cur + 1;
            }
        }
        return false;
    }
};