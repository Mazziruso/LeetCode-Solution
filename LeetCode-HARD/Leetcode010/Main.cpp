#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        //initial
        vector<vector<bool>> dp(len_s+1, vector<bool>(len_p+1));
        dp[0][0] = true;
        //special case;
        if(p[0]=='*') {
            return false;
        }
        for(int i=0; i<len_p; i++) {
            dp[0][i+1] = (p[i]=='*') ? dp[0][i-1] : dp[0][i+1];
        }
        //dp
        for(int i=0; i<len_s; i++) {
            for(int j=0; j<len_p; j++) {
                if(p[j]=='.' || s[i]==p[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[j] == '*') {
                    if(p[j-1] == '*') {
                        return false;
                    }
                    if(s[i] != p[j-1] && p[j-1]!='.') {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else if(s[i]==p[j-1] || p[j-1]=='.') {
                        dp[i+1][j+1] = (dp[i+1][j] | dp[i][j+1] | dp[i+1][j-1]);
                    }
                }
            }
        }
        return dp[len_s][len_p];
    }
};
