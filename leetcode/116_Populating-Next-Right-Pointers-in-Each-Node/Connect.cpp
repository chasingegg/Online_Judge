#include <iostream>
#include <vector>
#include <queue>
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
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* temp=q.front();

            q.pop();
            if(q.front()==NULL) {
                temp->next=NULL;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.push(NULL);
                q.pop();
            }
            else if(temp)
            {
                temp->next=q.front();
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};