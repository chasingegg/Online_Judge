#include <iostream>
#include <cstdio>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        if (m.count(root)) return m[root];
        int res = root->val;
        if (root -> left) {
            res += rob(root -> left -> left) + rob(root -> left -> right);
        }
        if (root -> right) {
            res += rob(root -> right -> left) + rob(root -> right -> right);
        }
        int another = rob(root -> left) + rob(root -> right);
        m[root] = max(res, another);
        return m[root];
    }
};