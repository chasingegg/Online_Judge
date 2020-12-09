#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gen(vector<vector<int>>& res, int n, int row, int col, int num) {
        if (n == 1) {
            res[row][col] = num;
            return;
        }
        if (n == 2) {
            res[row][col] = num;
            res[row][col+1] = num + 1;
            res[row+1][col+1] = num + 2;
            res[row+1][col] = num + 3;
            return;
        }
        for (int i = col; i < col + n - 1; ++i) {
            res[row][i] = num++;
        }
        for (int i = row; i < row + n - 1; ++i) {
            res[i][col + n - 1] = num++;
        }
        for (int i = col + n - 1; i > col; --i) {
            res[row + n - 1][i] = num++;
        }
        for (int i = row + n - 1; i > row; --i) {
            res[i][col] = num++;
        }
        gen(res, n-2, row+1, col+1, num);
    } 

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if (n <= 0) return res;
        gen(res, n, 0, 0, 1);
        return res;
    }
};