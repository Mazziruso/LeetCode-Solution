package Medium.LeetCode005;

public class Main {
    public static void main(String args[]) {
        Solution s = new Solution();
        System.out.println(s.longestPalindrome("abadda"));
    }
}

class Solution {
    private boolean dp[][]; //1 denotes a palindrome, 2 represents not a palindrome
    private int maxI;
    private int maxJ;
    public String longestPalindrome(String s) {
        int len = s.length();
        dp = new boolean[len][len];
        maxI = 0;
        maxJ = 0;
        //init
        for(int i=0;i<len;i++) {
            dp[i][i]=true;
        }
        for(int j=0;j<len;j++) {
            for(int i=j-1;i>=0;i--) {
                if(s.charAt(i)==s.charAt(j)) {
                    if(j-i<2) { //i+1>j-1
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                } else {
                    dp[i][j] = false;
                }
                if(dp[i][j] && (maxJ-maxI < j-i)) {
                    maxI = i;
                    maxJ = j;
                }
            }
        }

        if(len==0) {
            return s;
        } else {
            return s.substring(maxI, maxJ + 1);
        }
    }
}
