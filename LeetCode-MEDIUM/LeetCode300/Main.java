package Medium.LeetCode300;

import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        Solution s = new Solution();
        int nums[] = {10,9,2,5,3,7,101,18};
        System.out.println(s.lengthOfLISLog(nums));
    }
}

class Solution {
    public int lengthOfLIS(int[] nums) {
        int N = nums.length;
        int max;
        int maxDp = 0;
        int dp[] = new int[N];
        for(int i=0; i<N; i++) {
            max = 0;
            for(int k=0; k<i; k++) {
                if(nums[i]>nums[k] && max<dp[k]) {
                    max = dp[k];
                }
            }
            dp[i] = max + 1;
            maxDp = (maxDp<dp[i]) ? dp[i] : maxDp;
        }
        return maxDp;
    }
    //利用dp的递增性来进行二分搜索，dp[i]表示从0到此的子序列nums中的所有长为i的LIS中后缀的最小值
    //当前数字x，若dp[index-1]<x<=dp[index]，那么直接将dp[index]更新为x;若index>len的话，那么len++
    //最后返回len记为最长递增子序列长度
    public int lengthOfLISLog(int[] nums) {
        int N = nums.length;
        int dp[] = new int[N];
        int len = 0;
        int index;
        for(int i=0; i<N; i++) {
            index = binarySearch(1,len,nums[i],dp);
            dp[index] = nums[i];
            len = (index>len) ? (len + 1) : len;
        }
        return len;
    }
    private int binarySearch(int s, int e, int key, int[] dp) {
        int l = s;
        int r = e;
        int mid;
        while(l<=r) {
            mid = (l+r)/2;
            if(dp[mid]==key) {
                return mid;
            }
            else if(dp[mid]>key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}
