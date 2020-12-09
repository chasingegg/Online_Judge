#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); ++i) {
            // 1,4相交
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) {
                return true;
            }
            //1,5相交
            if ((i >= 4) && (x[i-1] == x[i-3] && x[i] >= x[i-2] - x[i-4])) {
                return true;
            }
            //1,6相交
            if ((i >= 5) && (x[i-2] >= x[i-4] && x[i-3] >= x[i-1] && x[i - 1] >= x[i - 3] - x[i - 5] && x[i] >= x[i - 2] - x[i - 4])) {
                return true;
            }
        }
        return false;
    }
};