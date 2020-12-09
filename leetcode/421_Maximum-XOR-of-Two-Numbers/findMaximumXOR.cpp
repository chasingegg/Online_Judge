#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 每个数都是32位的整型，树的高度就是32
class Solution {
public:
    struct TrieNode {
        TrieNode *left;
        TrieNode *right;
    };

    void insert(int n, TrieNode* head) {
        TrieNode* curr = head;
        for(int i = 31; i >= 0; i--) {
            int b = (n >> i) & 1;
            if(b == 0) {
                if(!curr->left) {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
            else {
                if(!curr->right) {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* head = new TrieNode();
        for(int i = 0; i < nums.size(); i++) {
            insert(nums[i], head);
        }
        int maxXorVal = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            TrieNode* curr = head;
            int currXorVal = 0;
            int val = nums[i];
            for(int j = 31; j >= 0; j--) {
                int b = (val >> j) & 1;
                if(b == 0) {
                    if(curr->right) { //反向而行
                        currXorVal += pow(2, j);
                        curr = curr->right;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if(curr->left) {
                        currXorVal += pow(2, j);
                        curr = curr->left;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
            if(currXorVal > maxXorVal) {
                maxXorVal = currXorVal;
            }
        }
        return maxXorVal;
    }
};