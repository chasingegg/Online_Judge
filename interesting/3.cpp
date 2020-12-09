/*
判断二叉树是否为平衡二叉树， 平衡二叉树表示左右子树高度差小于等于1 
想法是得到左右子树的深度看差值是否小于2，同时还要递归判断左右子树是否满足平衡二叉树的条件

方法是进行一次后序遍历，在计算深度的同时对以该节点为根节点的树做判断，
这样时间复杂度为O(N)
*/


#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    Node(Node *l=NULL, Node *r=NULL):left(l), right(r) {}
    ~Node() {}
};

Node *tree[1000] = {NULL};

bool isAVL(Node *root, int &depth) { 
    if (root == NULL) {
        depth = 0;
        return true;
    }
    int left = 0;
    int right = 0;
    if (isAVL(root->left, left) && isAVL(root->right, right)) {
        int pf = left - right;
        if ( abs(pf) < 2) {
            depth = 1 + (right > left)?right:left;
            return true;
        } 
    }
    return false;
}

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
    int d = 0;
    cout << isAVL(tree[0], d) << endl;
    return 0;
}