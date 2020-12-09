#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
private:
	int ROW; int COL;
	vector< vector<bool> > flag;

	void initial() {
		flag.resize(ROW);
		for (int i = 0; i < ROW; ++i) {
			flag[i].resize(COL);
		}
	}

	void initial_flag() {
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				flag[i][j] = false;
			}
		}
	}
public:
	bool dfs(vector<vector<char> > & board, int row, int col, string word, int index, int len, int numRow, int numCol) {

		if (flag[row][col] || word[index] != board[row][col]) {
			return false;
		}
		flag[row][col] = true;
		if (index == len - 1) {
			return true;
		}
		bool res = false;
		if (row > 0) {
			res = dfs(board, row - 1, col, word, index + 1, len, numRow, numCol);
		} 
		if (!res && row < numRow - 1) {
			res = dfs(board, row + 1, col, word, index + 1, len, numRow, numCol);
		}
		if (!res && col < numCol - 1) {
			res = dfs(board, row, col + 1, word, index + 1, len, numRow, numCol);
		}
		if (!res && col > 0) {
			res = dfs(board, row, col - 1, word, index + 1, len, numRow, numCol);
		}
		flag[row][col] = false;
		return res;
	}

    bool exist(vector<vector<char> > & board, string word) {
    	ROW = board.size();
    	if (ROW <= 0) {
    		return false;
    	} 
    	COL = board[0].size();
    	if (word.size() == 0) {
    		return true;
    	}

    	initial();
    	int len = word.size();
    	if (len > ROW * COL) {
    		return false;
    	}
    	for (int i = 0; i < ROW; ++i) {
    		for (int j = 0; j < COL; ++j) {
    			initial_flag();
	    		if (dfs(board, i, j, word, 0, len, ROW, COL)) {
	    			return true;
	    		}
    		}
    	}
        return false;
    }
};