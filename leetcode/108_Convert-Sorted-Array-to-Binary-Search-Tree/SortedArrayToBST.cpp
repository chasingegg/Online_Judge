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
    TreeNode* gen(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root -> left = gen(nums, start, mid-1);
        root -> right = gen(nums, mid+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return gen(nums, 0, nums.size()-1);
    }
};