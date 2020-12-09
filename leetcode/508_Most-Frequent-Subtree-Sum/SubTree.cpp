#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode *root, unordered_map<int,int> &map) {
        if (root == nullptr) return 0;
        int sum_left = 0;
        int sum_right = 0;
        if (root -> left != nullptr) {
            sum_left = dfs(root -> left, map);
            // map[sum_left]++;
        }
        if (root -> right != nullptr) {
            sum_right = dfs(root -> right, map);
            // map[sum_right]++;
        }
        map[sum_left + sum_right + root -> val]++;
        return sum_left + sum_right + root -> val;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> map;
        dfs(root, map);
        vector<int> res;
        int max_v = INT_MIN;
        for (auto m : map) {
            if (m.second > max_v) {
                max_v = m.second;
            }
        }
        for (auto m : map) {
            if (m.second == max_v) {
                res.push_back(m.first);
            }
        }
        return res;
    }
};