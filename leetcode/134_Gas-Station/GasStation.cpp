#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1;
        for (int i = 0; i < gas.size(); ++i) {
            int ga = 0;
            int f = 0;
            for (int j = i; j < i + cost.size(); j++) {
                int index = j % cost.size();
                ga += gas[index];
                if (!(ga >= cost[index])) { f = 1; break; }
                ga -= cost[index];
            }
            if (!f) return i; 
        }
        return res;
    }
};