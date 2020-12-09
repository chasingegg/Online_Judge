#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(string start, unordered_map<string, priority_queue<string, std::vector<string>, greater<string>>>& trips, vector<string>& res) {
        auto& destList = trips[start];
        while (!destList.empty()) {
            auto dest = destList.top();
            destList.pop();
            dfs(std::move(dest), trips, res);
        }   
        res.push_back(std::move(start));
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // [string -> vector<string>] 起始地 -> 目的地 的映射
        unordered_map<string, priority_queue<string, std::vector<string>, greater<string>>> trips;
        for (auto ticket : tickets) {
            if (trips.find(ticket[0]) == trips.end()) {
                trips[ticket[0]] = priority_queue<string, std::vector<string>, greater<string>>();
            }
            trips[ticket[0]].push(ticket[1]);
        }
        vector<string> res;
        dfs("JFK", trips, res);
        std::reverse(res.begin(), res.end());
        return res;
    }
};