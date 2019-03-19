#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int DFS(int s, int e) {
        if(s>=e) {
            return 1;
        }
        if(dp[s][e]>0) {
            return dp[s][e];
        }
        if(e-s<1) {
            dp[s][e] = 1;
            return 1;
        }
        int left, right;
        int sum=0;
        for(int i=s; i<=e; i++) {
            left = DFS(s, i-1);
            right = DFS(i+1, e);
            sum += left*right;
        }
        dp[s][e] = sum;
        return sum;
    }
    int numTrees(int n) {
        dp.resize(n+1, vector<int>(n+1,0));
        return DFS(1,n);
    }
};

int main() {

    cout << Solution().numTrees(20) << endl;

    return 0;
}