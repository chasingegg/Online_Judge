#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        if (n == 0) return len;
        vector<int> map(26, 0);
        for (int i = 0; i < len; ++i) {
            ++map[tasks[i] - 'A'];
        }
        sort(map.begin(), map.end());
        int res = 0;
        while (map[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[25] == 0) {
                    break;
                }
                if (i < 26 && map[25 - i] > 0) map[25-i]--;
                ++res;
                ++i;
            }
            sort(map.begin(), map.end());
        }
        return res;
    }
};