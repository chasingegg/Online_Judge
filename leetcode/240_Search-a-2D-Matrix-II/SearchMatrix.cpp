#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0; int y = m-1;
        while (x < n && y >= 0) {
            if (matrix[y][x] < target) {
                ++x;
            } else if (matrix[y][x] > target) {
                --y;
            } else return true;
        }
        return false;
    }
};