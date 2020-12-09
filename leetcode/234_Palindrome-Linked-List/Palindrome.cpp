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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *half = NULL;
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            head -> next = half;
            half = head;
            head = slow;
        }
        if (fast != NULL) slow = slow -> next;
        while (slow != NULL) {
            // cout << slow -> val << " " << half -> val << endl;
            if (slow -> val != half -> val) return false;
            slow = slow -> next;
            half = half -> next;
        }
        return true;
    }
};