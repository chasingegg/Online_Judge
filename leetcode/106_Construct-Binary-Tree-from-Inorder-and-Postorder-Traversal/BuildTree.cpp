#include <iostream>
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
    TreeNode* gen(vector<int>& inorder, int l1, int r1, 
        vector<int>& postorder, int l2, int r2) {
        if (l1 > r1 || l2 > r2) return NULL;
        int root_v = postorder[r2];
        int i;
        for (i = l1; i <= r1; ++i) {
            if (inorder[i] == root_v) break; 
        }
        TreeNode *root = new TreeNode(root_v);
        root -> left = gen(inorder, l1, i-1, postorder, l2, l2+i-1-l1);
        root -> right = gen(inorder, i+1, r1, postorder, l2+i-l1, r2-1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n <= 0) return NULL;
        return gen(inorder, 0, n-1, postorder, 0, n-1);
    }
};