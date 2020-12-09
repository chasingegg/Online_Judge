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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int len = 0;
        ListNode *cur = head;
        while (head -> next != NULL) {
            ++len;
            head = head -> next;
        }      
        ++len;
        ListNode *tail = head;
        head = cur;
        k = k % len;
        if (k == 0) return head;
        for (int i = 0; i < len - k - 1; ++i) {
            cur = cur -> next;
        }
        ListNode *h = cur -> next;
        cur ->next = NULL;
        tail -> next = head;
        return h;
    }
};