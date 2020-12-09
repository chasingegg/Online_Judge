#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void travel(TreeNode *node, int &res, int v) {
        int v_now = v * 10 + node -> val;
        if (node -> left == NULL && node -> right == NULL) {
            res += v_now;
        }
        if (node -> left != NULL) {
            travel(node->left, res, v_now);
        }
        if (node -> right != NULL) {
            travel(node->right, res, v_now);
        }
    } 
    int sumNumbers(TreeNode* root) {
        if (root == NULL) return 0;
        int res = 0;
        travel(root, res, 0);
        return res;
    }
};