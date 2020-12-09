#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode *> que;
        int depth = 1;
        que.push(root);
        while (!que.empty()) {
            vector<TreeNode*> tmp1;
            vector<int> tmp2;
            while (!que.empty()) {
                TreeNode *f = que.front();
                tmp1.push_back(f);
                tmp2.push_back(f -> val);
                que.pop();
            }
            if (depth % 2 == 1) {
                for (auto it = tmp1.rbegin(); it != tmp1.rend(); it++) {
                    if ((*it) -> right != NULL)
                        que.push((*it) -> right);
                    if ((*it) -> left != NULL)
                        que.push((*it) -> left);
                }
            } else {
                for (auto it = tmp1.rbegin(); it != tmp1.rend(); it++) {
                    if ((*it) -> left != NULL)
                        que.push((*it) -> left);
                    if ((*it) -> right != NULL)
                        que.push((*it) -> right);
                }
            }
            res.push_back(tmp2);
            ++depth;
        }
        return res;
    }
};