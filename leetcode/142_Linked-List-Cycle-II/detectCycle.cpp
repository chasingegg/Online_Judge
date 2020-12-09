#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;
        ListNode *slow, *fast;
        slow = fast = head;
        while (slow != NULL && fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast == NULL) break;
            fast = fast -> next;
            if (slow != NULL && fast != NULL && slow == fast) return slow;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *t = hasCycle(head);
        if (t == NULL) return NULL;
        ListNode *p1 = t;
        ListNode *p2 = head;
        while (p1 != p2) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};