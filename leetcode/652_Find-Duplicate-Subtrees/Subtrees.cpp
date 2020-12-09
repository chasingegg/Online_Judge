#include <iostream>
#include <vector>
#include <string>
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
    string dfs(TreeNode *root, unordered_map<string, int>& visited, vector<TreeNode*>& res) {
        if (root == nullptr) return "#";
        string left = dfs(root -> left, visited, res);
        string right = dfs(root -> right, visited, res);
        string cur = to_string(root->val) + "left" + left + "right" + right;
        ++visited[cur];
        
        if (visited[cur] == 2) {
            res.push_back(root);
        } 
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> visited;
        vector<TreeNode*> res;
        dfs(root, visited, res);
        return res;
    }
};