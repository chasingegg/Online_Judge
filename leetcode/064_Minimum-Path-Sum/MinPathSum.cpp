#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;
        vector<vector<int>> d(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                d[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < min(rows, cols); ++i) {
            if (i == 0) d[i][i] = grid[i][i];
            else d[i][i] = min(d[i-1][i], d[i][i-1]) + grid[i][i];
            for (int j = i + 1; j < cols; ++j) {
                if (i == 0) d[i][j] = d[i][j-1] + grid[i][j];
                else d[i][j] = min(d[i][j-1], d[i-1][j]) + grid[i][j];

            }
            for (int j = i + 1; j < rows; ++j) {
                if (i == 0) d[j][i] = d[j-1][i] + grid[j][i];
                else d[j][i] = min(d[j-1][i], d[j][i-1]) + grid[j][i];
            }
        }
        return d[rows-1][cols-1];
    }
};