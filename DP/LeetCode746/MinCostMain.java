package DPProblem.LeetCode746;

public class MinCostMain {
    public static void main(String[] args) {

//        int[] cost = {10, 15, 20};
        int[] cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//        int[] cost = {0,1,1,0};

        System.out.println(DPStairCase(cost));

    }

    public static int DPStairCase(int[] cost) {
        int n = cost.length;
        int[] c = new int[n];
        int q;

        c[0] = cost[0];
        c[1] = cost[1];

        for(int i=2; i<n; i++) {
            q = (c[i-1]<=c[i-2]) ? c[i-1] : c[i-2];
            c[i] = q + cost[i];
        }

        return (c[n-2]<=c[n-1]) ? c[n-2] : c[n-1];
    }
}
