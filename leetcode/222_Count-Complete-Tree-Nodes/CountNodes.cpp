#include <cmath>
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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }

};