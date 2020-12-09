#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        ListNode *h1 = head;
        ListNode *h2 = head;
        ListNode *h = head;
        ListNode *hh = head;
        ListNode *tmp = head;
        if (head -> val < x) {
            while (h1 -> next != NULL && h1 -> next -> val < x) {
                h1 = h1 -> next;
            }
            h2 = h1 -> next;
            if (h2 == NULL) return h1;
            hh = h2;
            tmp = h2 -> next;
            while (tmp  != NULL) {
                if (tmp -> val < x) {
                    h1 -> next = tmp;
                    h1 = h1 -> next;
                } else {
                    h2 -> next = tmp;
                    h2 = h2 -> next;
                }
                tmp = tmp -> next;
            }
            if (h2 != NULL) h2 -> next = NULL;
            h1 -> next = hh;
            return h;
        } else {
            while (h2 -> next != NULL && h2 ->next -> val >= x) {
                h2 = h2 -> next;
            }
            h1 = h2 -> next;
            if (h1 == NULL) return h2;
            h = h1;
            tmp = h1 -> next;
            while (tmp != NULL) {
                if (tmp -> val < x) {
                    h1 -> next = tmp;
                    h1 = h1 -> next;
                } else {
                    h2 -> next = tmp;
                    h2 = h2 -> next;
                }
                tmp = tmp -> next;
            }
            if (h2 != NULL) h2 -> next = NULL;
            h1 -> next = hh;
            return h;
        }

    }
};