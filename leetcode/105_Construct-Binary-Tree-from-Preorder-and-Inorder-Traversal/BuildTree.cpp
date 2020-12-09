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
    TreeNode *gen(vector<int>& preorder, int l1, int r1, 
        vector<int>& inorder, int l2, int r2) {
        if (l1 > r1 || l2 > r2) return NULL;
        int root_v = preorder[l1];
        int i;
        for (i = l2; i <= r2; ++i) {
            if (inorder[i] == root_v) break;
        }
        TreeNode *root = new TreeNode(root_v);
        root -> left = gen(preorder, l1+1, l1+i-l2, inorder, l2, i-1);
        root -> right = gen(preorder, l1+i-l2+1, r1, inorder, i+1, r2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n <= 0) return NULL;
        return gen(preorder, 0, n-1, inorder, 0, n-1);
    }
};