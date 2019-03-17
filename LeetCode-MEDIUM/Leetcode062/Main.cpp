#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==0 || n==0) {
            return 0;
        }
        vector<int> dp(m,1);
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[m-1];
    }
};

int main() {

    cout << Solution().uniquePaths(10,9) << endl;

    return 0;
}