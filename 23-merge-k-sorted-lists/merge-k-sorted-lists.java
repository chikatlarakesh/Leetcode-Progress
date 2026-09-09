/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n = lists.length;

        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.val));
        for(int i=0;i<n;i++) {
            if(lists[i] != null) pq.offer(lists[i]);
        }

        ListNode dummyHead = new ListNode(-1);
        ListNode prev = dummyHead;
        while(!pq.isEmpty()) {
            ListNode temp = pq.poll();
            prev.next = temp;
            prev = temp;

            if(temp.next != null) pq.offer(temp.next);
        }
        return dummyHead.next;
    }
}