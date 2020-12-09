#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i) {
            if (res.size() <= people[i][1]) {
                res.push_back(people[i]);
            } else {
                res.insert(res.begin()+people[i][1], people[i]);
            }
        }
        return res;
    }
};