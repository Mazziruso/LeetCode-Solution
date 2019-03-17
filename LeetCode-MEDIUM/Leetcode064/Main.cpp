#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) {
            return 0;
        }
        int m = grid[0].size();
        if(m==0) {
            return 0;
        }

        vector<ll> dp(m,0);
        dp[0] = grid[0][0];
        for(int i=1; i<m; i++) {
            dp[i] = dp[i-1] + grid[0][i];
        }
        for(int i=1; i<n; i++) {
            dp[0] += grid[i][0];
            for(int j=1; j<m; j++) {
                dp[j] = (dp[j]<dp[j-1]) ? dp[j]+grid[i][j] : dp[j-1]+grid[i][j];
            }
        }
        return dp[m-1];
    }
};

int main() {

    vector<vector<int>> grid({{1,3,1},{1,5,1},{4,2,1}});

    cout << Solution().minPathSum(grid) << endl;

    return 0;
}