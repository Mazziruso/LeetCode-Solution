#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();

        if(n==0) {
            return 0;
        }

        int m = obstacleGrid[0].size();

        if(m==0) {
            return 0;
        }
        
        vector<ll> dp(m,0);

        dp[0] = obstacleGrid[0][0]==1 ? 0 : 1;
        for(int i=1; i<m; i++) {
            dp[i] = obstacleGrid[0][i]==1 ? 0 : dp[i-1];
        }

        for(int i=1; i<n; i++) {
            dp[0] = obstacleGrid[i][0]==1 ? 0 : dp[0];
            for(int j=1; j<m; j++) {    
                if(obstacleGrid[i][j]==1) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[m-1];
    }
};

int main() {

    vector<vector<int>> grid({{0,0,0},{0,1,0},{0,0,0}});

    cout << Solution().uniquePathsWithObstacles(grid) << endl;

    return 0;
}
