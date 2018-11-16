package DPProblem.LeetCode741;

public class CherryPU {
    public static void main(String[] args) {

//        int[][] grid = {{0,1,-1}, {1,0,-1}, {1,1,1}};
//        int[][] grid = {{0,-1,0}, {-1,1,1}, {1,0,1}};
//        int[][] grid = {{0,0,0}, {0,0,0}, {0,0,0}};
//        int[][] grid = {{1}};
        int[][] grid = {{1,1,1,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{1,0,0,1,0,0,1},{0,0,0,1,0,0,0},{0,0,0,1,0,0,0},{0,0,0,1,1,1,1}};
        int N = grid.length;

        int[][] dp = new int[N][N];


        printMat(grid);

        int res = cherryPickUp(grid, dp);

        printMat(dp);

        System.out.println(res);

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

    public static void printMat(char[][] mat) {
        System.out.println();

        for(int i=0; i<mat.length; i++) {
            for(int j=0; j<mat[i].length; j++) {
                System.out.printf("%5c", mat[i][j]);
            }
            System.out.println();
        }

        System.out.println();
    }

    public static int cherryPickUp(int[][] grid, int[][] dp) {
        int N = grid.length;
        int nMax = 2*N-2;
        int j;
        int q;

        //while grid is null, return zero
        if(N == 0) {
            return 0;
        }

        dp[0][0] = grid[0][0];

        for(int n=1; n<=nMax; n++) {
            for(int i=N-1; i>=0; i--) {
                for(int p=N-1; p>=0; p--) {
                    j = n-i;
                    q = n-p;

                    if(j<0 || j>=N || q<0 || q>=N || grid[i][j]<0 || grid[p][q]<0) {
                        dp[i][p] = -1;
                        continue;
                    }

                    if(i>0) {
                        dp[i][p] = Math.max(dp[i][p], dp[i-1][p]);
                    }

                    if(p>0) {
                        dp[i][p] = Math.max(dp[i][p], dp[i][p-1]);
                    }

                    if(i>0 && p>0) {
                        dp[i][p] = Math.max(dp[i][p], dp[i-1][p-1]);
                    }

                    if(dp[i][p] >=0) {
                        dp[i][p] += (grid[i][j] + ((i == p) ? 0 : grid[p][q]));
                    }

                }
            }
        }

        return Math.max(dp[N-1][N-1], 0);

    }


//貪心內的遞歸，本問題不符合貪心子問題性質
//    public static int cherryPickUp(int[][] grid, int[][] c, char[][] b) {
//        int sum = 0;
//        int N = grid.length;
//
//        //while grid is null, return zero
//        if(N == 0) {
//            return 0;
//        }
//
//        //Dynamic Programing
//
//        //start out from [0][0]
//        c[0][0] = grid[0][0];
//        b[0][0] = 'n';
//
//        for(int i=1; i<N; i++) {
//            if(grid[0][i]==-1 || c[0][i-1]==-1) {
//                c[0][i] = -1;
//                b[0][i] = 'n';
//            } else {
//                c[0][i] = c[0][i-1] + grid[0][i];
//                b[0][i] = 'r';
//            }
//
//            if(grid[i][0]==-1 || c[i-1][0]==-1) {
//                c[i][0] = -1;
//                b[i][0] = 'n';
//            } else {
//                c[i][0] = c[i-1][0] + grid[i][0];
//                b[i][0] = 'd';
//            }
//        }
//
//        for(int i=1; i<N; i++) {
//            for(int j=1; j<N; j++) {
//                if(grid[i][j]>=0 && (c[i][j-1]!=-1 || c[i-1][j]!=-1)) {
//                    c[i][j] = ((c[i-1][j] >= c[i][j-1]) ? c[i-1][j] : c[i][j-1]) + grid[i][j];
//                    b[i][j] = (c[i-1][j] >= c[i][j-1]) ? 'd' : 'r';
//                } else {
//                    c[i][j] = -1;
//                    b[i][j] = 'n';
//                }
//            }
//        }
//
//
//        //while it can not pass, return zero
//        if(c[N-1][N-1] == -1) {
//            return 0;
//        }
//
//        //way-going, max numbers of cherry picked up
//        sum += c[N-1][N-1];
//
//        //reback, update matrix grid
//        int bi = N-1;
//        int bj = N-1;
//        while(bi>=0 && bj>=0) {
//            grid[bi][bj] = 0;
//            if(b[bi][bj] == 'd') {
//                bi--;
//            } else if(b[bi][bj] == 'r') {
//                bj--;
//            } else {
//                break;
//            }
//        }
//
//        //reback, from [N-1][N-1] to [0][0]
//        c[N-1][N-1] = grid[N-1][N-1];
//        for(int i=N-2; i>=0; i--) {
//            if(grid[N-1][i]==-1 || c[N-1][i+1]==-1) {
//                c[N-1][i] = -1;
//            } else {
//                c[N-1][i] = c[N-1][i+1] + grid[N-1][i];
//            }
//
//            if(grid[i][N-1]==-1 || c[i+1][N-1]==-1) {
//                c[i][N-1] = -1;
//            } else {
//                c[i][N-1] = c[i+1][N-1] + grid[i][N-1];
//            }
//        }
//
//        for(int i=N-2; i>=0; i--) {
//            for(int j=N-2; j>=0; j--) {
//                if(grid[i][j]>=0 && (c[i][j+1]!=-1 || c[i+1][j]!=-1)) {
//                    c[i][j] = ((c[i+1][j] >= c[i][j+1]) ? c[i+1][j] : c[i][j+1]) + grid[i][j];
//                } else {
//                    c[i][j] = -1;
//                }
//            }
//        }
//
//        if(c[0][0] == -1) {
//            return 0;
//        }
//
//        sum += c[0][0];
//
//        return sum;
//
//    }
}
