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
        TreeNode *cur = root;
        TreeNode *last = NULL;
        while (cur != NULL || !st.empty()) {
            // 一路向左
            while (cur != NULL) {
                st.push(cur);
                cur = cur -> left;
            }
            cur = st.top();
            // 右节点为NULL，或者已经访问过
            if (cur -> right == NULL || cur -> right == last) {
                res.push_back(cur -> val);
                st.pop();
                last = cur; // 已经访问
                cur = NULL;  // 继续弹栈
            } else {
                cur = cur -> right;
            }
        }
        return res;
    }
};