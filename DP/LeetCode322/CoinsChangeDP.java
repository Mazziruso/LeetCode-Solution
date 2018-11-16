package DPProblem.LeetCode322;

import java.util.Arrays;

public class CoinsChangeDP {
    public static void main(String[] args) {

        int[] coins = {4, 6 ,7};

        System.out.println(coinChange(coins, 3));

    }

    public static int coinChange(int[] coins, int amount) {
        int K = coins.length;

        if(amount == 0) {
            return 0;
        }

        if(K == 0) {
            return -1;
        }

        quickSort(coins, 0, K-1);

        int[] c = new int[amount+1];
        int q;
        int k;

        for(int i=1; i<=amount; i++) {
            q = Integer.MAX_VALUE;
            k = 0;

            while(k<K && coins[k]<=i) {
                if(c[i-coins[k]]>=0 && q>c[i-coins[k]]) {
                    q = c[i-coins[k]];
                }
                k++;
            }
            c[i] = (q<Integer.MAX_VALUE) ? q+1 : -1;
        }

        return c[amount];

    }

    private static int partition(int[] A, int start, int end) {
        int x = A[end];
        int i = start-1;

        int temp;
        for(int j=start; j<end; j++) {
            if(A[j]<=x) {
                i++;
                temp = A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }

        i++;
        A[end] = A[i];
        A[i] = x;

        return i;
    }

    private static int randomizedPartition(int[] A, int start, int end) {
        int index = (int)(Math.random()*(end-start)) + start;

        int temp = A[index];
        A[index] = A[end];
        A[end] = temp;

        return partition(A, start, end);
    }

    private static void quickSort(int[] A, int start, int end) {
        if(start < end) {
            int q = randomizedPartition(A, start, end);
            quickSort(A, start, q-1);
            quickSort(A, q+1, end);
        }
    }
}
