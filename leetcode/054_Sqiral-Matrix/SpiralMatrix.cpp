#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
public:
    void spiral(vector<vector<int>>& ma, vector<int>& res, int row, int col, int rown, int coln, int index) {
        if (2*row+1 > rown) return;
        if (2*col+1 > coln) return;
        int row_margin = rown - row;
        int col_margin = coln - col;
        if (2 * row + 1 == rown) {
            for (int i = row; i < col_margin; ++i) {
                res[index++] = ma[i][col];
            }
            return;
        }
        if (2 * col + 1 == coln) {
            for (int i = col; i < row_margin; ++i) {
                res[index++] = ma[row][i];
            }
            return;
        }
        for (int i = col; i < row_margin-1; ++i) {
            res[index++] = ma[row][i];
        }        
        for (int i = row; i < col_margin-1; ++i) {
            res[index++] = ma[i][row_margin-1];
        }
        for (int i = row_margin-1; i > col; --i) {
            res[index++] = ma[col_margin-1][i];
        }
        for (int i = col_margin-1; i > row ; --i) {
            res[index++] = ma[i][col];
        }
        spiral(ma, res, row+1, col+1, rown, coln, index);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int num_row = matrix.size();
        if (num_row <= 0) return vector<int>();
        int num_col = matrix[0].size(); 
        vector<int> res(num_row * num_col, 0);
        spiral(matrix, res, 0, 0, num_col, num_row, 0);
        return res;
    }
};