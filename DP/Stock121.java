package LeetCodeDP;

public class Stock121 {
    public static void main(String[] args) {
//        int[] prices = {7, 1, 5, 3, 6 ,4};
//        int[] prices = {7,6,5,4,3,2,1};
        int[] prices = {1,5};
        System.out.println(maxProfit(prices));

    }

    public static int maxProfit(int[] prices) {
        int n = prices.length;
        if(n<=1) {
            return 0;
        }

        int[] margins = new int[n-1];

        for(int i=0; i<(n-1); i++) {
            margins[i] = prices[i+1] - prices[i];
        }

        int[] c = new int[n-1];
        int max;

        c[0] = margins[0];
        max = c[0];

        for(int i=1; i<(n-1); i++) {
            if(c[i-1]>=0) {
                c[i] = c[i-1] + margins[i];
            } else {
                c[i] = margins[i];
            }

            if(max <= c[i]) {
                max = c[i];
            }
        }


        return (max>0) ? max : 0;
    }
}
