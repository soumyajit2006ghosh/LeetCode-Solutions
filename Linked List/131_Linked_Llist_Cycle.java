// Slow-First Pointer Approach >>
// Check that the two pointers meets each other or not
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;

        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;  // Moving 'slow' by one node
            fast = fast.next.next;  // Moving 'fast' by two nodes
            if (slow == fast)
                return true;
        }
        return false;
    }
}
