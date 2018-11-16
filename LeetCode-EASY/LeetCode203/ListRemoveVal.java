package Easy.LeetCode203;

public class ListRemoveVal {
    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(6);
        head.next.next.next = new ListNode(6);
        head.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next = new ListNode(5);
        head.next.next.next.next.next.next = new ListNode(6);

        ListNode newList = removeElements(head, 6);

        printList(head);
        printList(newList);

    }

    private static void printList(ListNode head) {
        ListNode node = head;

        while(node != null) {
            System.out.print(node.val + "->");
            node = node.next;
        }
        System.out.println();
    }

    private static ListNode removeElements(ListNode head, int val) {
        ListNode node = head;
        ListNode next = (node==null) ? null : node.next;
        ListNode prev = head;

        while(node != null) {
            if(node.val == val) {
                if(node == head) {
                    head = next;
                    node.next = null;
                } else {
                    prev.next = next;
                    node.next = null;
                }

                node = next;
                next = (node==null) ? null : node.next;
            } else {
                prev = node;
                node = next;
                next = (node==null) ? null : node.next;
            }
        }

        return head;
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        this.val = x;
    }
}
