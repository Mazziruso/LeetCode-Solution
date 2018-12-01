package LeetCodeMedium.LeetCode050;

public class Main {
    public static void main(String args[]) {
        Solution s = new Solution();
        System.out.println(s.myPow(2.0,-2147483648));
    }
}

class Solution {
    public double myPow(double x, int n) {
        long pn = n; //avoid -n being overflow
        x = (pn<0) ? 1/x : x;
        pn = (pn<0) ? -pn : pn;
        double res;

        res = 1;
        while(pn>0) {
            if((pn&1) == 1) {
                res = res * x;
            }
            x = x * x;
            pn = pn >> 1;
        }

        return res;
    }
}
