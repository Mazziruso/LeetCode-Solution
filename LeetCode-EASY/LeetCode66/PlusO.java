package Easy.LeetCode66;

import java.util.Vector;
public class PlusO {
    public static void main(String[] args) {
        int[] nums = {9,9,9,9,9,9,9,9,9,9,9};

        int[] digits = plusOne(nums);

        for(int i=0; i<digits.length; i++) {
            System.out.print(digits[i] + " ");
        }
    }

    public static int[] plusOne(int[] digits) {
        Vector<Integer> dig = new Vector<Integer>();

        int temp = 0;
        boolean carry = true;
        for(int i=digits.length-1; i>=0; i--) {
            if(carry) {
                temp = (digits[i]+1) % 10;
                dig.addElement(temp);
            } else {
                dig.addElement(digits[i]);
            }

            if(temp != 0) {
                carry = false;
            } else {
                carry = true;
            }
        }

        if(carry) {
            dig.addElement(1);
        }

        int size = dig.size();
        int[] res = new int[size];
        for(int i=0; i<size; i++) {
            res[i] = dig.elementAt(size-i-1);
        }

        return res;
    }
}
