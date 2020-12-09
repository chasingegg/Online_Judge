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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            vector<TreeNode*> tmp;
            vector<int> res_tmp;
            while (!que.empty()) {
                TreeNode *f = que.front();
                tmp.push_back(f);
                que.pop();
                res_tmp.push_back(f -> val);
            }
            for (auto v : tmp) {
                if (v -> left != NULL) que.push(v -> left);
                if (v -> right != NULL) que.push(v -> right);
            }
            res.push_back(res_tmp);
        }
        return res;
    }
};