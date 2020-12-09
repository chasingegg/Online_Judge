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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;
        if (root == NULL) return res;
        que.push(root);
        int size = 1;
        while (!que.empty()) {
            vector<int> tmp;
            int count = 0;
            for (int i = 0; i < size; ++i) {
                auto cur = que.front();
                tmp.push_back(cur -> val);
                if (cur -> left != NULL) {
                    ++count;
                    que.push(cur -> left);
                }
                if (cur -> right != NULL) {
                    ++count;
                    que.push(cur -> right);
                }
                que.pop();
            }
            res.push_back(tmp);
            size = count;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};