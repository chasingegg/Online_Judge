#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> map;
        for (int i = 0; i < n; ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]]++;
            }
        }
        for (auto x : map) {
            // cout << x.first << " " << x.second << endl;
            if (pq.size() < k) {
                pq.emplace(x.first, x.second);
            } else {
                if (x.second > pq.top().second) {
                    pq.emplace(x.first, x.second);
                    pq.pop();
                }
            }
        }
        while (!pq.empty()) {
            res.emplace_back(pq.top().first);
            // cout << pq.top().second << " " << pq.top().first << endl;
            pq.pop();
        }
        return res;
    }
};