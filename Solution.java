
public class Solution {

    public void reorderList(ListNode head) {

        //Find middle node.
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        //Reverse nodes in the second part, starting from the middle.
        ListNode current = slow;
        ListNode previous = null;
        ListNode temp;
        while (current != null) {
            temp = current.next;
            current.next = previous;
            previous = current;
            current = temp;
        }

        //Combine the nodes of the first and second part, in alternating manner.
        ListNode odd = head;
        ListNode even = previous;
        while (even.next != null) {
            temp = odd.next;
            odd.next = even;
            odd = temp;

            temp = even.next;
            even.next = odd;
            even = temp;
        }
    }
}

class ListNode {

    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
