// 学习字典树
// 根据现有的单词构建出一棵树，公共前缀是关键
// 一个数都可以表示成32位的二进制格式，每一位是0或1，给一个数组就可以构建出一课高度为32的字典树，而且这时候
// 这个字典树一定是二叉树，实现起来比较方便
// 任意给一个数，要想异或最大，那么就是说如果说当前位是1，那么就在树上找0的节点，反之同理，这样就可以快速找到找到最大异或值
// 复杂度从O(N)降到O(logN)

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[30005];
int b[30005];
int tmp[32];

int N, M;

struct node {
    int value;
    node *left;
    node *right;
    node(int v = -1, node *l = NULL, node *r = NULL) { left = l; right = r; value = v; }
    ~node() {}
};

void trans(int num) {
    for(int i = 31; i >= 0; --i) {
        tmp[i] = (num >> (31 - i)) & 1;
    }
}

void insert(node *root, int num) {
    node *cur = root;
    trans(num);
    for(int i = 0; i < 31; ++i) {
        if (tmp[i]) {
            if (!(cur -> right))
                cur -> right = new node();
            cur = cur -> right;
        } else {
            if (!(cur -> left))
                cur -> left = new node();
            cur = cur -> left;
        }
    }
    if(tmp[31]) {
        if (!(cur -> right))
            cur -> right = new node(num);
    } else {
        if (!(cur -> left))
            cur -> left = new node(num);
    }
}

int find(node *root, int num) {
    node *cur = root;
    trans(num);
    for(int i = 0; i < 32; ++i) {
        if(tmp[i]) {
            if(cur -> left)
                cur = cur -> left;
            else 
                cur = cur -> right;
        }
        else {
            if(cur -> right)
                cur = cur -> right;
            else
                cur = cur -> left;
        }
    }
    return num ^ (cur -> value);
}

int main() {
    node *root = new node();
    int ans = 0;
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < M; ++i) {
        scanf("%d", &b[i]);
        insert(root, b[i]);
    }
    for(int i = 0; i < N; ++i) {
        ans = max(ans, find(root, a[i]));
    }
    cout << ans << endl;
    return 0;
}