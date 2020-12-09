#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode *root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        inorder(root -> left, res);
        res.push_back(root -> val);
        inorder(root -> right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // inorder(root, res);
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != NULL || !st.empty()) {
            while (cur != NULL) {
                st.push(cur);
                cur = cur -> left;
            }
            cur = st.top();
            st.pop();
            res.push_back(cur -> val);
            cur = cur -> right;
        }
        return res;
    }
};