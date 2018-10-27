package LeetCodeDP;

/*
最優子結構：
    條件：c[i,k]代表在nums數組從第i開始至最後一個數的子數組中，將之分割成k個子子數組，求一種分割方案
         使得這k個子子數組最大和最小化的最大和最小值

    原問題由子問題的最優解構成：
        c[i,k] = min{max{sum[i->j], c[j+1,k-1]}, i<=j<=n}, k>=1;
                 sum[i->n], k=1
 */

public class SplitArray410 {
    public static void main(String[] args) {
        int[] nums = {7,2,10,5,8};
        int m = 2;

        int res = splitArray(nums, m);

        System.out.println(res);
    }

    public static int splitArray(int[] nums, int m) {
        int n = nums.length;
        int q;
        int temp;
        int[] sum = new int[n+1];

        sum[0] = 0;
        for(int i=1; i<=n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }

        int[][] c = new int[n][m];

        for(int i=1; i<=n; i++) {
            c[i-1][0] = sum[n] - sum[i-1];
        }

        for(int i=n-1; i>=1; i--) {
            for(int k=m; k>=2; k--) {
                if(k <= (n-i+1)) {
                    q = Integer.MAX_VALUE;
                    for(int j=i; j<=(n-k+1); j++) {
                        temp = Math.max(sum[j]-sum[i-1], c[j][k-2]);
                        if(q > temp) {
                            q = temp;
                        }
                    }

                    c[i-1][k-1] = q;
                }
            }
        }

        return c[0][m-1];
    }
}
