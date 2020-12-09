#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
TreeNode* merge(TreeNode *left, TreeNode *right)
{
	if (left == NULL) return right;
	if (right == NULL) return left;
	TreeNode *cur = left;
	while (cur->right != NULL)
		cur = cur->right;
	cur->right = right;
	return left;
}
void helper(TreeNode *root, TreeNode *pre, int key, int flag)
{
	if (root == NULL) return;
	if (root->left && key < root->val)
		helper(root->left, root, key, 0);
	else if ( root->right && key > root->val)
		helper(root->right, root, key, 1);
	else if(root->val == key)
	{
		if (flag == 0) pre->left = merge(root->left, root->right);
		else pre->right = merge(root->left, root->right);
	}
}
TreeNode* deleteNode(TreeNode* root, int key) {
	if (root == NULL) return root;
	if (root->left && key < root->val) helper(root->left, root, key, 0);
	else if(root->right && key > root->val) helper(root->right, root, key, 1);
	else if(root->val==key) return merge(root->left, root->right);

	return root;
}
};