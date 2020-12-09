#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val) {
    	val = _val;
    }

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
	void Swap(Node *&n1, Node *&n2) {
		Node *tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	Node *TheLast(Node *head) {
		if (head -> next == NULL && head -> child == NULL) {
			return head;
		}
		if (head -> child == NULL) {
			return TheLast(head -> next); 
		}
		if (head -> next == NULL) {
			head -> next = head -> child;
			head -> child -> prev = head;
			head -> child = NULL;
			return TheLast(head -> next);
		}
		Swap(head->next, head->child);
		head -> next -> prev = head;
		Node *tail = TheLast(head->next);
		tail -> next = head -> child;
		head -> child -> prev = tail;
		head -> child = NULL;
		return TheLast(tail->next);
	}

    Node* flatten(Node* head) {
    	if (head == NULL) {
    		return NULL;
    	}
    	TheLast(head);
    	return head;
        
    }
};