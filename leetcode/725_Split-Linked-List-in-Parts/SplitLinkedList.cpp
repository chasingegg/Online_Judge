#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode *cur = root;
        vector<ListNode *> res;
        if (k == 0) return res;
        if (root == NULL) {
            for (int i = 0; i < k; ++i) {
                res.push_back(NULL);
            }
            return res;
        }
        while (cur != NULL) {
            ++len;
            cur = cur -> next;
        }
        int size;
        if (len % k != 0) {
            size = len / k + 1;
        } else {
            size = len / k;
        }
        int a, b;
        a = len - k * (size-1);
        b = k - a;
        for (int i = 0; i < a; ++i) {
            ListNode *head = root;
            for (int j = 0; j < size-1; ++j) {
                root = root -> next;
            }
            ListNode *tmp = root -> next;
            root -> next = NULL;
            res.push_back(head);
            root = tmp;
        }
        if (a == len) {
            for (int i = len; i < k; ++i) {
                res.push_back(NULL);
            }
            return res;
        }
        for (int i = 0; i < b; ++i) {
            ListNode *head = root;
            for (int j = 0; j < size-2; ++j) {
                root = root -> next;
            }
            ListNode *tmp = root -> next;
            root -> next = NULL;
            res.push_back(head);
            root = tmp;
        }
        return res;
    }
};