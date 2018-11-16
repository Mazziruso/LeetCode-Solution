package Medium.LeetCode002;

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int sum = 0;
        ListNode res = new ListNode(0);
        ListNode nodeR = res;
        while(l1!=null && l2!=null) {
            sum = l1.val + l2.val + carry;
            carry = sum / 10;
            sum = sum % 10;
            nodeR.next = new ListNode(sum);
            l1 = l1.next;
            l2 = l2.next;
            nodeR = nodeR.next;
        }
        while(l1 != null) {
            sum = l1.val + carry;
            carry = sum / 10;
            sum = sum % 10;
            nodeR.next = new ListNode(sum);
            l1 = l1.next;
            nodeR = nodeR.next;
        }
        while(l2 != null) {
            sum = l2.val + carry;
            carry = sum /10;
            sum = sum % 10;
            nodeR.next = new ListNode(sum);
            l2 = l2.next;
            nodeR = nodeR.next;
        }
        if(carry>0) {
            nodeR.next = new ListNode(carry);
        }
        return res.next;
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        this.val = x;
    }
}
