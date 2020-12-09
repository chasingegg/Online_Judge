#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map <Node*, Node*> node_map; 
		// node_map[address of original list node] = address of copied list node
        // i.e. Node *copied = new Node(orig_node); then node_map[orig_node] = copied
        
        Node* new_head = new Node(head->val);
        new_head->random = head->random;
        node_map[head] = new_head;
        head = head->next;
        
        Node *new_temp = new_head;
        while (head != nullptr){
            Node* copy_node = new Node(head->val);
            node_map[head] = copy_node; // point from original node to copied node
            copy_node->random = head->random; // now just point to original list node, later i can use the map
            
            new_temp->next = copy_node;
            head = head->next;
            new_temp = new_temp->next;
        }
        
        new_temp = new_head;
        while (new_temp != nullptr){// point random to the copied nodes
            new_temp->random = node_map[new_temp->random];
            new_temp = new_temp->next;
        }
        return new_head;
    }
};
