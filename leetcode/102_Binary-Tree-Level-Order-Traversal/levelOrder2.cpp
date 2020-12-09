#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> res;
    void build(TreeNode* root, int depth) {
        if (root == NULL) return;
        if (res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root -> val);
        build(root -> left, depth + 1);
        build(root -> right, depth + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        build(root, 0);
        return res;
    }
};