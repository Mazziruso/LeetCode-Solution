package LeetCodeDP;

public class PerfectSquares279 {
    public static void main(String[] args) {

        System.out.println(numSquares(1));

    }

    public static int numSquares(int n) {
        int[] c = new int[n+1];
        int q;
        int k;

        for(int i=1; i<=n; i++) {
            k = (int) Math.floor(Math.sqrt(i));
            q = Integer.MAX_VALUE;

            for(int j=1; j<=k; j++) {
                if(q > c[i-j*j]) {
                    q = c[i-j*j];
                }
            }

            c[i] = q + 1;
        }

        return c[n];

    }
}
