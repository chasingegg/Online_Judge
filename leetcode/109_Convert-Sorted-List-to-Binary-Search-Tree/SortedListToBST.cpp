#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *gen(vector<int>& list, int l, int r) {
        if (l > r) return nullptr;
        int cur = l + (r - l) / 2;
        TreeNode *root = new TreeNode(list[cur]);
        root -> left = gen(list, l, cur-1);
        root -> right = gen(list, cur+1, r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> list;
        while (head != NULL) {
            list.push_back(head -> val);
            head = head -> next;
        }
        return gen(list, 0, list.size()-1);
    }
};