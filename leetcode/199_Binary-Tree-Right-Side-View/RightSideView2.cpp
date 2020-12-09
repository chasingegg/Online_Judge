#include <iostream>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        queue<TreeNode *> que;
        que.push(root);
        TreeNode *prev, *cur;
        int level_size = 0;
        while (!que.empty()) {
            level_size = que.size();
            for (int i = 0; i < level_size; ++i) {
                cur = que.front();
                que.pop();
                if (cur -> left != NULL) que.push(cur -> left);
                if (cur -> right != NULL) que.push(cur -> right);
                prev = cur;
            }
            res.push_back(prev -> val);
        }
        return res;
    }
};