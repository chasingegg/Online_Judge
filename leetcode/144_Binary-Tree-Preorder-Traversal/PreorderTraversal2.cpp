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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        if (root == NULL) return res;
        st.push(root);
        while (!st.empty()) {
            auto tt = st.top();
            st.pop();
            res.push_back(tt -> val);
            if (tt -> right != NULL)
                st.push(tt -> right);
            if (tt -> left != NULL)
                st.push(tt -> left);
        }
        return res;
    }
};