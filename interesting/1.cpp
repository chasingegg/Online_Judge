/*
计算二叉树的两节点的最大距离
考虑两种情况即可：1. 路径经过根节点，即左右子树的高度之和 2. 路径不经过
根节点，取左右子树最大距离中较大者

*/
#include <iostream>
#include <cstdio>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    Node(Node *l=NULL, Node *r=NULL):left(l), right(r) {}
    ~Node() {}
};

// 计算高度的同时把maxDistance计算好，厉害了
int height(Node* n, int &maxDistance) {
    if (n == NULL) return -1;
    int h_left = height(n->left, maxDistance) + 1;
    int h_right = height(n->right, maxDistance) + 1;

    int h = h_left + h_right;
    maxDistance = maxDistance > h ? maxDistance : h;
    return h_left > h_right ? h_left : h_right;
}

Node *tree[1000] = {NULL};

void link(int parent, int left, int right) {
    if (left != -1) tree[parent]->left = tree[left];
    if (right != -1) tree[parent]->right = tree[right];
}

int main() {
    for(int i = 0; i < 1000; ++i) {
        tree[i] = new Node();
    }

    link(0, 1, 2);
    link(1, 3, 4);
    link(2, 5, 6);
    link(3, 7, -1);
    link(5, -1, 8);
    int dis = 0;
    height(tree[0], dis);
    cout << dis << endl;
}