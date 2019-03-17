#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool visC[9][9];
	bool visR[9];

	bool isValidSudoku(vector<vector<char>>& board) {
		//initialize
		for (int i = 0; i < 9; i++) {
			fill_n(visC[i], 9, false);
		}

		for (int i = 0; i < 9; i++) {
			fill_n(visR, 9, false);
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					if (!visR[board[i][j] - '1'] && !visC[j][board[i][j] - '1']) {
						visR[board[i][j] - '1'] = true;
						visC[j][board[i][j] - '1'] = true;
					}
					else {
						return false;
					}
				}
			}
		}

		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				fill_n(visR, 9, false);
				for (int k1 = i; k1 < i + 3; k1++) {
					for (int k2 = j; k2 < j + 3; k2++) {
						if (board[k1][k2] != '.') {
							if (!visR[board[k1][k2] - '1']) {
								visR[board[k1][k2] - '1'] = true;
							}
							else {
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};