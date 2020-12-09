#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    typedef pair<int, pair<int, int>> pp;

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.size() == 0) return 0;
        int n = matrix[0].size();
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(matrix[0][i], make_pair(0, i));
        }
        pp f;
        while (k--) {
            f = pq.top();
            pq.pop();
            int row = f.second.first;
            int col = f.second.second;
            if (row < n-1) {
                pq.emplace(matrix[row + 1][col], make_pair(row + 1, col));
            }
        }
        return f.first;
    }
};