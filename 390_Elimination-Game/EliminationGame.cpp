#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1 || n == 2) return n;
        if (n % 2 == 0) {
            return n - 2 * lastRemaining(n/2) + 2;
        } else {
            return lastRemaining(n-1);
        }
    }
};