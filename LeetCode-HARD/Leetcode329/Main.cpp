#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    vector<int> dx;
    vector<int> dy;
    int n;
    int m;
    vector<vector<int>> mat;
    vector<vector<int>> dp;

    int DFS(int x, int y) {
        if(dp[x][y]>0){
            return dp[x][y];
        }
        int len = 1;
        int nx;
        int ny;
        for(int i=0; i<4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(mat[x][y] < mat[nx][ny]) {
                    len = max(len, DFS(nx, ny)+1);
                }
            }
        }
        dp[x][y] = len;
        return len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->n = matrix.size();

        if(this->n == 0) {
            return 0;
        }

        this->m = matrix[0].size();
        this->dx = {-1,0,1,0};
        this->dy = {0,-1,0,1};
        this->mat = matrix;
        this->dp.resize(n, vector<int>(m, 0));

        int len = 1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                len = max(len, DFS(i, j));
            }
        }

        return len;
    }
};

int main() {

    vector<vector<int>> mat({{3,4,5},{3,2,6},{2,2,1}});

    cout << Solution().longestIncreasingPath(mat) << endl;

    return 0;
}