#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        if (root -> val == sum && root -> left == NULL && root -> right == NULL) {
            vector<int> tmp;
            tmp.push_back(root -> val);
            res.push_back(tmp);
            return res;
        }
        vector<vector<int>> l = pathSum(root->left, sum-root->val);
        vector<vector<int>> r = pathSum(root->right, sum-root->val);
        if (l.size() != 0) {
            for (auto ll : l) {
                vector<int> tmp;
                tmp.push_back(root->val);
                tmp.insert(tmp.end(), ll.begin(), ll.end());
                res.push_back(tmp);
            }
        } 
        if (r.size() != 0) {
            for (auto rr : r) {
                vector<int> tmp;
                tmp.push_back(root->val);
                tmp.insert(tmp.end(), rr.begin(), rr.end());
                res.push_back(tmp);
            }
        }
        return res;
    }
};