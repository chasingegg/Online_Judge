#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
	int ROW;
	int COL;

public:
	int dfs(vector<vector<int> >& matrix, int row, int col, vector<vector<int> >& f) {
		if (f[row][col] != 0) {
			return f[row][col];
		} 
		int res1 = 0, res2 = 0, res3 = 0, res4 = 0;
		if (row > 0 && matrix[row-1][col] > matrix[row][col]) {
			res1 = dfs(matrix, row-1, col, f);
		} 
		if (row < ROW - 1 && matrix[row+1][col] > matrix[row][col]) {
			res2 = dfs(matrix, row+1, col, f);
		}
		if (col > 0 && matrix[row][col-1] > matrix[row][col]) {
			res3 = dfs(matrix, row, col-1, f);
		}
		if (col < COL - 1 && matrix[row][col+1] > matrix[row][col]) {
			res4 = dfs(matrix, row, col+1, f);
		}
		f[row][col] = 1 + max(res1, max(res2, max(res3, res4)));
		return f[row][col];
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROW = matrix.size();
        if (ROW <= 0) {
        	return 0;
        }
        COL = matrix[0].size();
        vector<vector<int> > f(ROW, vector<int>(COL, 0));
        int res = 0;
        for (int i = 0; i < ROW; ++i) {
        	for (int j = 0; j < COL; ++j) {
       			int fo = dfs(matrix, i, j, f);
       			cout << fo << endl;
        		res = max(res, fo);
        	}
        }
        return res;
    }
};