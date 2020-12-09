#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	struct TrieNode {
		char val;
		string ans;
		TrieNode *children[26];
		bool InAnswer;
		bool isEnd;

		TrieNode(char v) {
			val = v;
			InAnswer = false;
			isEnd = false;
			for (int i = 0; i < 26; ++i) {
				children[i] = NULL;
			}
		}
	};

	TrieNode *root;

	void insert(string str) {
		TrieNode *tmp = root;
		for (int i = 0; i < str.size(); ++i) {
			if (tmp -> children[str[i]-'a'] == NULL) {
				tmp -> children[str[i]-'a'] = new TrieNode(str[i]);
				tmp -> children[str[i]-'a'] -> ans = (tmp == root) ? string(1, str[i]) : (tmp -> ans + str[i]);
			}
			tmp = tmp -> children[str[i]-'a'];
		}
		tmp -> isEnd = true;
	}

	void Print(TrieNode *node) {
		if (node == NULL) {
			return;
		}
		if (node -> isEnd) {
			cout << node -> ans << endl;
		}
		for (int i = 0; i < 26; ++i) {
			Print(node -> children[i]);
		}
	}

public:
	vector<string> Find(vector<vector<char>>& board, int row, int col, int numROW, int numCOL, TrieNode *node) {
		vector<string> res;
		if (node == NULL || board[row][col] == '*') {  // 没有该值，或者已经被访问过了
			return res;
		}
		char c = board[row][col];
		board[row][col] = '*';
		if (node -> isEnd && !(node -> InAnswer)) {
			res.push_back(node -> ans);
			node -> InAnswer = true;
		} 
		vector<string> tmp;
		if (row > 0 && board[row-1][col] != '*') { 
			tmp = Find(board, row - 1, col, numROW, numCOL, node->children[board[row-1][col]-'a']);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		if (row < numROW - 1 && board[row+1][col] != '*') {
			tmp = Find(board, row + 1, col, numROW, numCOL, node->children[board[row+1][col]-'a']);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		if (col > 0 && board[row][col-1] != '*') {
			tmp = Find(board, row, col - 1, numROW, numCOL, node->children[board[row][col-1]-'a']);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		if (col < numCOL - 1 && board[row][col+1] != '*') {
			tmp = Find(board, row, col + 1, numROW, numCOL, node->children[board[row][col+1]-'a']);
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
		board[row][col] = c;
		return res;

	}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    	vector<string> res;
        root = new TrieNode('&');
        if (words.size() == 0) {
        	return res;
        }
        for (int i = 0; i < words.size(); ++i) {
        	insert(words[i]);
        }
        // Print(root);

        int ROW = board.size();
        if (ROW == 0) {
        	return res;
        }
        int COL = board[0].size();
        vector<string> tmp;
        for (int i = 0; i < ROW; ++i) {
        	for (int j = 0; j < COL; ++j) {
        		tmp = (Find(board, i, j, ROW, COL, root->children[board[i][j]-'a']));
        		res.insert(res.begin(), tmp.begin(), tmp.end());
        	}
        }
        return res;
    }
};