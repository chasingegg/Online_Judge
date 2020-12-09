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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL; // leetcode总是卡这个
        ListNode *cur, *tail, *res;
        cur = head;
        res = head;
        int len = 0;
        while (cur != NULL) {
            ++len;
            cur = cur -> next;
        }
        cur = head -> next;
        tail = cur;
        for (int i = 0; i < len/2-1; ++i) {
            head -> next = head -> next -> next;
            cur -> next = cur -> next -> next;
            head = head -> next;
            cur = cur -> next;
        }
        if ((len & 1) && len > 1) {
            head -> next = head -> next -> next;
            head = head -> next;
        }
        if (cur) cur -> next = NULL;
        head -> next = tail;
        return res;
    }
};