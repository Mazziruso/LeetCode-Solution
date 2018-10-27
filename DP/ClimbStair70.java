package LeetCodeDP;

public class ClimbStair70 {
    public static void main(String[] args) {

        for(int i=0; i<=10; i++) {
            System.out.println(climbStairs(100));
        }

    }

    public static long climbStairs(int n) {
        if(n==1) {
            return 1L;
        } else if(n==2) {
            return 2L;
        }

        long c = 0L;
        long a = 1L;
        long b = 2L;

        for(int i=3; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
}
