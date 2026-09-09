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

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0;i<n;i++) {
            ListNode temp = lists[i];
            while(temp != null) {
                pq.offer(temp.val);
                temp = temp.next;
            }
        }

        ListNode dummyHead = new ListNode(1);
        ListNode prev = dummyHead;
        while(!pq.isEmpty()) {
            ListNode temp = new ListNode(pq.poll());
            prev.next = temp;
            prev = temp;
        }
        return dummyHead.next;
    }
}