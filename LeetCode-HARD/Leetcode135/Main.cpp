#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    vector<int> dp;
    vector<int> rates;

    int DFS(int index, int n) {
        if(dp[index]>0) {
            return dp[index];
        }
        int l = (index==0) ? 0 : index-1;
        int r = (index==n-1) ? n-1 : index+1;

        if(rates[l]>=rates[index] && rates[r]>=rates[index]) {
            dp[index]=1;
            return 1;
        } else if(rates[l]<rates[index] && rates[r]<rates[index]) {
            dp[index] = max(DFS(l, n), DFS(r, n)) + 1;
        } else if(rates[l]>=rates[index] && rates[r]<rates[index]) {
            dp[index] = DFS(r, n) + 1;
        } else if(rates[l]<rates[index] && rates[r]>=rates[index]) {
            dp[index] = DFS(l, n) + 1;
        }
        return dp[index];
    }
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        this->rates = ratings;
        this->dp.resize(n, 0);

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += DFS(i, n);
        }
        return sum;
    }
};

class Solution1 {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();

        vector<int> candy(n, 1);
        int sum = 0;

        //Forward
        for(int i=1; i<n; i++) {
            candy[i] = (ratings[i]>ratings[i-1]) ? candy[i-1]+1 : candy[i];
        }
        //reverse
        for(int i=n-2; i>=0; i--) {
            candy[i] = (ratings[i+1]<ratings[i] && candy[i]<candy[i+1]) ? candy[i+1]+1 : candy[i];
        }

        for(int i=0; i<n; i++) {
            sum += candy[i];
        }
        return sum;
    }
};

int main() {

    vector<int> rates({1,1,2});

    cout << Solution().candy(rates) << endl;
    cout << Solution1().candy(rates) << endl;

    return 0;
}