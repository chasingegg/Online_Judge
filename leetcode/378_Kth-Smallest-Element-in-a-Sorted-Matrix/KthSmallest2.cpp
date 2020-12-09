#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int countSmallEqual(vector<vector<int>>& matrix, int x) {
        int row = 0;
        int col = matrix[0].size() - 1;
        int count = 0;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] > x) {
                --col;
            } else {
                count += col + 1;
                ++row;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int start = matrix[0][0];
        int m = matrix.size();
        int n = matrix[0].size();
        int end = matrix[m-1][n-1];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count = countSmallEqual(matrix, mid);
            if (count < k) {
                start = mid + 1; // <k 说明至少结果是mid+1，因为这里包含相等的情况了
            } else {
                end = mid - 1;
            }
        }
        return start;
    }
};