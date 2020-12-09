#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 层次遍历 递归
// 按照level 
class Solution {
public:
    void levelOrder(TreeNode *root, int level, vector<vector<int>>& res) {
        if (root == NULL) return;
        if (res.size() == level) {
            res.push_back(vector<int>());
        }
        res[level].push_back(root -> val);
        levelOrder(root -> left, level + 1, res);
        levelOrder(root -> right, level + 1, res);
    } 

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};