#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *HEAD = new ListNode(0);
        HEAD -> next = head;
        ListNode *p1, *p2;
        p1 = p2 = HEAD;
        for (int i = 0; i < n; ++i) {
        	p2 = p2 -> next;
        }
        while (p2 -> next != NULL) {
        	p2 = p2 -> next;
        	p1 = p1 -> next;
        }
        p1 -> next = p1 -> next -> next;
        return HEAD -> next;
    }
};