#include <iostream>
#include <cstdio>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *goLeft(Node *root) {
        if (root -> left != NULL) {
            return root -> left;
        } else {
            return root -> right;
        }
    }

    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        Node *left = connect(root -> left);
        Node *right = connect(root -> right);
        if (left != NULL) left -> next = right;
        Node *tmp = left;
        Node *tmp2 = right;
        while (tmp != NULL && tmp2 != NULL) {
            while (tmp -> left == NULL && tmp -> right == NULL && tmp -> next != tmp2)
                tmp = tmp -> next;
            tmp = goLeft(tmp); // 寻找左路
            while (tmp2 -> left == NULL && tmp2 -> right == NULL && tmp2 -> next != NULL)
                tmp2 = tmp2 -> next;          
            tmp2 = goLeft(tmp2);
            if (tmp == NULL) break;
            Node *tt = tmp;
            while (tt -> next != NULL) tt = tt -> next; // 找到最右边 
            // 为什么不直接一路找最右，就怕找不到
            if (tt != NULL) {
                tt -> next = tmp2; // 相连
            }
        }
        return root;
    }
};