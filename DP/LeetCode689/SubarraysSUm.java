package DPProblem.LeetCode689;

import java.util.Arrays;

/*
最優子結構：
條件：nums下標從第i開始到結尾的子序列中，找出j個子數組（其中0<=j<=3），這j個子數組大小均為k
    那麼c[i,j]代表滿足上述條件的j個子數組和的最大值
遞歸：滿足重疊子問題，即c[i,j] = max{c[i+1,j], c[i+k,j-1]+sum(nums[i~i+k-1])}
構造最優解值：最優解構造標b[i,j]代表黨c[i,j]選擇後者時設為當前的i
時間複雜度O(n)，空間複雜度O(n)
 */

public class SubarraysSUm {
    public static void main(String[] args) {
        int[] nums = {1,2,1,2,6,7,5,1,7,7,4};

        int k = 3;

        int N = nums.length;

        int[][] c = new int[N+1][4];
        int[][] b = new int[N][3];

        int[] indiceArrays = maxSumOfThreeSubarrays(nums, k, c, b);

//        printMat(c);
//        printMat(b);

        System.out.println(Arrays.toString(indiceArrays));

    }

    public static void printMat(int[][] mat) {
        System.out.println();

        for(int i=0; i<mat.length; i++) {
            for(int j=0; j<mat[i].length; j++) {
                System.out.printf("%5d", mat[i][j]);
            }
            System.out.println();
        }

        System.out.println();
    }

    public static void printSubarraysIndice(int[][] b, int k, int N) {
        int i = 0;
        int j = 2;

        System.out.println();

        while(j>=0) {
            while(b[i][j] == b[i+1][j]) {
                i++;
            }

            System.out.print(b[i][j] + " ");

            i = b[i][j] + k;
            j--;
        }

        System.out.println();
    }

    public static int[] maxSumOfThreeSubarrays(int[] nums, int k, int[][] c, int[][] b) {
        int N = nums.length;
//        int[][] c = new int[N+1][4]; //substructure optimal value table
//        int[][] b = new int[N][3]; //reconstruction table
        int q;
        int[] sum = new int[N+1];//maintain a array record sum of subset

        sum[N-1] = nums[N-1];
        for(int i=N-2; i>=N-k+1; i--) {
            sum[i] = sum[i+1] + nums[i];
        }

        for(int j=1; j<=3; j++) {

            for(int i=N-k; i>=0; i--) {
                sum[i] = sum[i+1] + nums[i];
                b[i][j-1] = (i<N-1) ? b[i+1][j-1] : 0;

                q = c[i+1][j];
                if(q <= (c[i+k][j-1]+sum[i]-sum[i+k])) {
                    q = c[i+k][j-1] + sum[i]-sum[i+k];
                    b[i][j-1] = i;
                }

                c[i][j] = q;
            }
        }

        //reconstruct the optimal solution
        int[] subarraysIndice = new int[3];
        int i = 0;
        int j = 2;
        while(j >= 0) {
            while(b[i][j] == b[i+1][j]) {
                i++;
            }
            subarraysIndice[2-j] = b[i][j];
            i = b[i][j] + k;
            j--;
        }

        return subarraysIndice;

    }
}
