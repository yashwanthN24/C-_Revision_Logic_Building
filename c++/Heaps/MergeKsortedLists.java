import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

class Solution {

    public ListNode mergeKLists(ListNode[] lists) {

        // Min-heap: smallest node comes first
        PriorityQueue<ListNode> pq =
            new PriorityQueue<>((a, b) -> a.val - b.val);

        // Put first node of every list into heap
        for (ListNode head : lists) {
            if (head != null) {
                pq.add(head);
            }
        }

        // Dummy node
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        while (!pq.isEmpty()) {

            // Get smallest node
            ListNode curr = pq.poll();

            // Add it to answer
            tail.next = curr;
            tail = curr;

            // Add next node from same list
            if (curr.next != null) {
                pq.add(curr.next);
            }
        }

        return dummy.next;
    }
}