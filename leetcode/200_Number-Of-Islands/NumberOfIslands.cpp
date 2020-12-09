#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, int rows, int cols, vector<vector<char>>& grid, vector<vector<int>>& flag) {
        if (i > 0 && grid[i-1][j] == '1' && !flag[i-1][j]) {
            flag[i-1][j] = 1;
            dfs(i-1, j, rows, cols, grid, flag);
        }
        if (i < rows-1 && grid[i+1][j] == '1' && !flag[i+1][j]) {
            flag[i+1][j] = 1;
            dfs(i+1, j, rows, cols, grid, flag);
        }
        if (j > 0 && grid[i][j-1] == '1' && !flag[i][j-1]) {
            flag[i][j-1] = 1;
            dfs(i, j-1, rows, cols, grid, flag);
        }
        if (j < cols-1 && grid[i][j+1] == '1' && !flag[i][j+1]) {
            flag[i][j+1] = 1;
            dfs(i, j+1, rows, cols, grid, flag);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows <= 0) return 0;
        int cols = grid[0].size();
        vector<vector<int>> flag(rows, vector<int>(cols, 0));
        int res = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1' && flag[i][j] == 0) {
                    ++res;
                } else continue;
                flag[i][j] = 1;
                
                dfs(i, j, rows, cols, grid, flag);
            }
        }
        return res;
    }
};