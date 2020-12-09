#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, bool> map;
        for (int i = 0; i < arr.size(); ++i) {
            if (map.count(arr[i] * 2) == 0) {
                map[arr[i]] = true;
            } else {
                return true;
            }
            if (arr[i] % 2 == 0 && arr[i] != 0) {
                if (map.count(arr[i] / 2) > 0) {
                     return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution so;
    vector<int> nums = {-2,0,10,-19,4,6,-8};
    cout << so.checkIfExist(nums) << endl;
    return 0;
}