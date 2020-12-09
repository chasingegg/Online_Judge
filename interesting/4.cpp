/*
反转链表

*/

#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int num;
    Node *next;
    Node(int n = 0, Node *ne = NULL):num(n),next(ne) {}
    ~Node() {}
};

Node *l[100];

void recursive_invert(Node *p) {
    if (p->next == NULL || p == NULL) return;
    recursive_invert(p->next);
    p->next->next = p;
    p->next = NULL;
}

void invert(Node *p) {
    if (p->next == NULL || p == NULL) return;
    Node *cur = p, *pre = p;
    while (cur->next != NULL) {
        Node *tmp = cur->next->next;
        cur->next->next = pre;
        pre = cur->next;
        cur->next = tmp;
    }
}

int main() {
    l[0] = new Node(0);
    for (int i = 1; i < 100; ++i) {
        l[i] = new Node(i);
        l[i-1]->next = l[i];
    }
    l[99]->next = NULL;

    //--------- 递归反转
    recursive_invert(l[0]);
    Node *temp = l[99];
    while (temp != NULL) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
    // -------- 迭代反转
    invert(l[99]);
    temp = l[0];
    while (temp != NULL) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    return 0;

}