/*
寻找二叉树中两节点最近的公共父节点
仍然是递归的想法，先分别在左右子树找，分别找到的话则最近公共父节点是根节点
如果不是则在左右子树递归下去
*/

#include <iostream>
using namespace std;

struct Node {
    int num;
    Node *left;
    Node *right;
    Node(int n = 0, Node *l = NULL, Node *r = NULL):num(n),left(l), right(r) {}
    ~Node() {}
};

Node *tree[100];

void link(int parent, int left, int right) {
    if (left != -1) tree[parent]->left = tree[left];
    if (right != -1) tree[parent]->right = tree[right];
}

Node* find(Node *root, Node *n1, Node *n2) {
    if (root == NULL) return NULL;
    if (root == n1 || root == n2) {
        return root;
    }
    Node *lres = find(root->left, n1, n2);
    Node *rres = find(root->right, n1, n2);
    if (lres != NULL && rres != NULL) {
        return root;
    }
    return lres == NULL?rres:lres;
}

int main() {
    for(int i = 0; i < 100; ++i) {
        tree[i] = new Node(i);
    }

    link(0, 1, 2);
    link(1, 3, 4);
    link(2, 5, 6);
    link(3, 7, -1);
    link(5, -1, 8);

    Node *res = find(tree[0], tree[7], tree[4]);
    cout << res->num << endl;
    return 0;
}