#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int Count(TreeNode *root) {
        if (root == NULL) return 0;
        return  Count(root -> left) + Count(root -> right) + 1;
    } 

    int kthSmallest(TreeNode* root, int k) {
        int sum_left;
        sum_left = Count(root -> left);
        if (sum_left == k-1) {
            return root -> val;
        } else if (sum_left > k-1) {
            return kthSmallest(root -> left, k);
        }
        return kthSmallest(root -> right, k - sum_left - 1);

    }
};