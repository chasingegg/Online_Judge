/*
链表倒数第k个节点
*/
// 维护两个指针，一开始两个指针都指在链表开头，第一个指针先后移k个节点，(如果链表的长度少于k，则返回一个NULL)，
// 这时两个指针一起向后移动，直到第一个指针到达末尾，则第一个指针就在倒数第k个节点的位置上

#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    int num;
    Node *next;
    Node(int n = 0, Node *ne = NULL):num(n), next(ne) {}
    ~Node() {}
};

Node *l[100];

int main() {
    l[0] = new Node(0);
    for (int i = 1; i < 100; ++i) {
        l[i] = new Node(i);
        l[i-1]->next = l[i];
    }
    l[99]->next = NULL;
    int k;
    cin >> k;
    if(k > 100) {
        cout << "return null" << endl;
        return 0;
    }
    Node *p1, *p2;
    p1 = p2 = l[0];
    for (int i = 0; i < k; ++i) {
        p2 = p2->next;
    }
    while (p2 != NULL) {
        p2 = p2->next;
        p1=p1->next;
    }
    cout << p1->num << endl;
    return 0;
}
