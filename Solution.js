
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function (head) {

    //Find middle node.
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }

    //Reverse nodes in the second part, starting from the middle.
    let current = slow;
    let previous = null;
    let temp;
    while (current !== null) {
        temp = current.next;
        current.next = previous;
        previous = current;
        current = temp;
    }

    //Combine the nodes of the first and second part, in alternating manner.
    let odd = head;
    let even = previous;
    while (even.next !== null) {
        temp = odd.next;
        odd.next = even;
        odd = temp;

        temp = even.next;
        even.next = odd;
        even = temp;
    }
};

function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}
