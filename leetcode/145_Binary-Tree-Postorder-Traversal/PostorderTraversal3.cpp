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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;
        if (root != NULL) {
            st.push(root);
            while (!st.empty()) {
                auto node = st.top();
                res.push_back(node -> val);
                st.pop();
                if (node -> left != NULL) {
                    st.push(node -> left);
                }
                if (node -> right != NULL) {
                    st.push(node -> right);
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};