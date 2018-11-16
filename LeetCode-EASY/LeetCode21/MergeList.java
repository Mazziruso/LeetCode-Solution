package Easy.LeetCode21;

public class MergeList {

    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(2);
        l1.next.next = new ListNode(4);

        ListNode l2 = new ListNode(1);
        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);
        l2.next.next.next = new ListNode(5);
        l2.next.next.next.next = new ListNode(6);

        ListNode l = mergeTwoLists(l1, l2);

        ListNode p = l;
        while(p != null) {
            System.out.println(p.val);
            p = p.next;
        }

    }

    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //if l1 or l2 is null
        if(l1 == null) {
            return l2;
        } else if(l2 == null) {
            return l1;
        }

        ListNode l = new ListNode();
        ListNode p = l;

        ListNode p1 = l1;
        ListNode p2 = l2;

        //merge two linked lists
        if(p1.val > p2.val) {
            p.val = p2.val;
            p2 = p2.next;
        } else {
            p.val = p1.val;
            p1 = p1.next;
        }

        while(p1!=null && p2!=null) {
            p.next = new ListNode();
            p = p.next;

            if(p1.val > p2.val) {
                p.val = p2.val;
                p2 = p2.next;
            } else {
                p.val = p1.val;
                p1 = p1.next;
            }
        }

        if(p1 == null) {
            p.next = p2;
        } else {
            p.next = p1;
        }

        return l;
    }
}

class ListNode {
    int val;
    ListNode next;

    public ListNode(int val) {
        this.val = val;
    }

    public ListNode() {
        this(0);
    }
}
