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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false;
        ListNode *slow, *fast;
        slow = fast = head;
        while (slow != NULL && fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
            if (fast == NULL) break;
            fast = fast -> next;
            if (slow != NULL && fast != NULL && slow == fast) return true;
        }
        return false;
    }
};