#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool inRow(vector<int> &row, int target) {
        if (row.size() == 0) return false;
        if (row[0] > target) return false;
        return true;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (!inRow(matrix[i], target)) return false;
            if (target <= matrix[i][matrix[i].size()-1]) {
                int j = 0;
                int k = matrix[i].size()-1;
                while (j <= k) {
                    int kk = (j + k) / 2;
                    if (target == matrix[i][kk]) {
                        return true;
                    } else if (target < matrix[i][kk]) {
                        k = kk - 1;
                    } else {
                        j = kk + 1;
                    }
                }
            }
        }
        return false;
    }
};