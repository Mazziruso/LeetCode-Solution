package Easy.LeetCode409;

public class LPalindrome {
    public static void main(String[] args) {

        String s = "zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez";
        System.out.println(longestPalindrome(s));

    }

    public static int longestPalindrome(String s) {
        int[] num = new int[52];

        int asc;
        for(int i=0; i<s.length(); i++) {
            asc = (int)s.charAt(i);

            if(asc>=65 && asc<=90) {
                num[asc-65]++;
            } else {
                num[asc-71]++;
            }
        }

        boolean flag = false;
        int length = 0;
        for(int i=0; i<52; i++) {
            if(num[i]%2 == 1) {
                flag = true;
            }
            length += (num[i]%2==0) ? num[i] : (num[i]-1);
        }

        if(flag) {
            length++;
        }

        return length;
    }
}
