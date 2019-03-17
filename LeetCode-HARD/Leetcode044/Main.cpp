#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s = s.length();
        int len_p = p.length();
        vector<vector<bool>> dp(len_s+1, vector<bool>(len_p+1, false));
        //initial
        dp[0][0] = true;
        for(int i=0; i<len_p; i++) {
            dp[0][i+1] = (p[i]=='*') ? dp[0][i] : dp[0][i+1];
        }
        //dp
        for(int i=0; i<len_s; i++) {
            for(int j=0; j<len_p; j++) {
                if(s[i]==p[j] || p[j]=='?') {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[j]=='*') {
                    dp[i+1][j+1] = (dp[i][j+1] | dp[i+1][j]);
                }
            }
        }
        return dp[len_s][len_p];
    }
    bool isMatchLinearSpace(string s, string p) {
		int len_s = s.length();
		int len_p = p.length();
		vector<bool> dp(len_p + 1, false);
		//initial
		dp[0] = true;
		for (int i = 0; i < len_p; i++) {
			dp[i + 1] = (p[i] == '*') ? dp[i] : dp[i + 1];
		}
		//dp
		bool last_dp;
		bool tmp;
		for (int i = 0; i < len_s; i++) {
			last_dp = dp[0];
			dp[0] = false;
			for (int j = 0; j < len_p; j++) {
				tmp = dp[j + 1];
				if (s[i] == p[j] || p[j] == '?') {
					dp[j + 1] = last_dp;
				}
				else if (p[j] == '*') {
					dp[j + 1] = (dp[j + 1] | dp[j]);
				}
				else {
					dp[j + 1] = false;
				}
				last_dp = tmp;
			}
		}
		return dp[len_p];
	}
    bool isMatchDoublePointer(string s, string p) {
        int index_s = 0;
        int index_p = 0;
        int match_s = 0;
        int star_last = -1;
        int len_s = s.length();
        int len_p = p.length();
        //遍历整个主字符串
        while(index_s < len_s) {
            // 无*匹配，两指针同时后移
            if(index_p<len_p && (s[index_s]==p[index_p] || p[index_p]=='?')) {
                index_s++;
                index_p++;
            // 碰到 *，假设它匹配空串，并且用 star_last 记录 * 的位置，记录当前字符串的位置，index_p后移    
            } else if(index_p<len_p && p[index_p] == '*') {
                star_last = index_p;
                match_s = index_s;
                index_p++;
            //当前字符串不匹配且没有*，则将模式串指针回退到最近的'*'处star_last；
            //match_s更新到下一位置，index_s回到更新后的match_s，这一步代表了用*匹配了一个字符
            } else if(star_last >= 0) {
                index_p = star_last+1;
                match_s++;
                index_s=match_s;
            //字符不匹配，也没有 *，返回 false
            } else {
                return false;
            }
        }

        //将末尾多余的 * 直接匹配空串
        while(index_p<len_p && p[index_p]=='*') {
            index_p++;
        }

        return index_p==len_p;
    }
};