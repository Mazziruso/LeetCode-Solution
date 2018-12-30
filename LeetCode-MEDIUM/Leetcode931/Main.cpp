#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int minT(int a, int b, int c) {
		a = (a < b) ? a : b;
		return (a < c) ? a : c;
	}
	int minFallingPathSum(vector<vector<int>> &A) {
		if (A.size() == 1) {
			return A[0][0];
		}
		int N = A.size();
		vector<vector<int>> DP(N, vector<int>(N, 0));
		//initial
		for (int i = 0; i < N; i++) {
			DP[0][i] = A[0][i];
		}
		//DP
		for (int i = 1; i < N - 1; i++) {
			DP[i][0] = min(DP[i - 1][0], DP[i - 1][1]) + A[i][0];
			DP[i][N - 1] = min(DP[i - 1][N - 2], DP[i - 1][N - 1]) + A[i][N - 1];
			for (int j = 1; j < N - 1; j++) {
				DP[i][j] = minT(DP[i - 1][j], DP[i - 1][j - 1], DP[i - 1][j + 1]) + A[i][j];
			}
		}
		//N-1
		int minSum;
		DP[N - 1][0] = min(DP[N - 2][0], DP[N-2][1]) + A[N - 1][0];
		DP[N - 1][N - 1] = min(DP[N - 2][N - 2], DP[N - 2][N - 1]) + A[N - 1][N - 1];
		minSum = min(DP[N - 1][0], DP[N - 1][N - 1]);
		for (int j = 1; j < N - 1; j++) {
			DP[N - 1][j] = minT(DP[N - 2][j], DP[N - 2][j - 1], DP[N - 2][j + 1]) + A[N - 1][j];
			minSum = (DP[N - 1][j] < minSum) ? DP[N - 1][j] : minSum;
		}
		//result solution
		return minSum;
	}
};

int main() {

	Solution s;
	
	int myints[5][5] = { {-11, -48, -69, 6, -3},{12, 51, 77, -1, -38},{-7, 62, 75, 63, -63},{100, 27, -84, 45, 98},{-20, 36, -37, -58, 44} };

	vector<vector<int>> A(5, vector<int>(5, 0));

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			A[i][j] = myints[i][j];
		}
	}
	
	printf("%d\n", s.minFallingPathSum(A));
	system("pause");
	return 0;
}