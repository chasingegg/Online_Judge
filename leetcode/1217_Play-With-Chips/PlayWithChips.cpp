#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int shuang = 0;
        int odd = 0;
        for (int i = 0; i < chips.size(); ++i) {
            if (chips[i] % 2 == 0) {
                shuang++;
            } else {
                odd++;
            }
        }
        return shuang < odd ? shuang : odd;
    }
};