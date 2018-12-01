package Medium.LeetCode006;

public class Main {
    public static void main(String arge[]) {
        Solution s = new Solution();
        System.out.println(s.convert("A", 1));
    }
}

class Solution {
    public String convert(String s, int numRows) {
        StringBuffer str = new StringBuffer();
        int len = s.length();
        int step = (numRows==1) ? 1: 2*numRows-2; //步进大小
        for(int r=0; r<numRows; r++) {
            for(int i=r; i<len; i+=step) {
                //正常间距点
                str.append(s.charAt(i));
                //中间斜线点
                if(r>0 && r<numRows-1 && (i-2*r+step)<len) {
                    str.append(s.charAt(i-2*r+step));
                }
            }
        }
        return str.toString();
    }
}
