package Easy.LeetCode661;

public class ImageSmoother {
    public static void main(String[] args) {

        int[][] M = new int[][] {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};

        int[][] Mres = imageSmoother(M);

        printMat(Mres);

    }

    private static void printMat(int[][] M) {
        for(int i=0; i<M.length; i++) {
            for(int j=0; j<M[i].length; j++) {
                System.out.print(M[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] imageSmoother(int[][] M) {
        int[][] Img = new int[M.length][];

        for(int i=0; i<M.length; i++) {
            Img[i] = new int[M[i].length];
            for(int j=0; j<M[i].length; j++) {
                Img[i][j] = filterVal(M, i, j);
            }
        }


        return Img;
    }

    public static int filterVal(int[][] M, int i, int j) {
        int res = 0;
        int num = 0;

        for(int ii=i-1; ii<=i+1; ii++) {
            for(int jj=j-1; jj<=j+1; jj++) {
                if(ii>=0 && ii<M.length && jj>=0 && jj<M[ii].length) {
                    res += M[ii][jj];
                    num++;
                }
            }
        }

        res /= num;

        return res;
    }
}
