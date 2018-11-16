package Easy.LeetCode9;

public class PalindromeNumber {
    public static void main(String[] args) {

        int N = 10;
        int num;

        for(int i=0; i<N; i++) {
            num = (int)(Math.random()*1000.0);
            System.out.println(num + ": " + isPalindrome(num));
        }

    }

    public static boolean isPalindrome(int x) {
        if(x < 0) {
            return false;
        } else if(x == 0) {
            return true;
        }

        int temp = x;
        int count = 0;

        while(temp >= 1) {
            temp = temp / 10;
            count++;
        }

        temp = x;
        int y = 0;
        for(int i=0; i<count; i++) {
            y += (int)(Math.pow(10, (count-i-1))) * (temp%10);
            temp = temp / 10;
        }

        return y==x;
    }
}
