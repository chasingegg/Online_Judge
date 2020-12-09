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
    vector<TreeNode*> generate(int left, int right) {
        vector<TreeNode *> res;
        if (left > right) {
            return vector<TreeNode *>{NULL};
        }
        for (int i = left; i <= right; ++i) {
            vector<TreeNode *> left_res = generate(left, i-1);
            vector<TreeNode *> right_res = generate(i+1, right);
            for (auto &l : left_res) {
                for (auto &r : right_res) {
                    TreeNode *root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return vector<TreeNode*>();
        return generate(1, n);
    }
};