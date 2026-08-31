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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode left = head;
        ListNode curr = head.next;
        List<Integer> criticalPoints = new ArrayList<>();
        int index = 1;

        while(curr.next != null) {
            ListNode right = curr.next;
            if((curr.val > left.val && curr.val > right.val) || 
                (curr.val < left.val && curr.val < right.val)) {
                    criticalPoints.add(index);
                }
            
            left = curr;
            curr = curr.next;
            index++;
        }

        int n = criticalPoints.size();
        if(n <= 1) return new int[]{-1,-1};

        Collections.sort(criticalPoints);
        int maxDistance = criticalPoints.get(n-1) - criticalPoints.get(0);

        int minDistance = Integer.MAX_VALUE;
        for(int i=1;i<n;i++) {
            minDistance = Math.min(minDistance,criticalPoints.get(i) - criticalPoints.get(i-1));
        } 
        return new int[]{minDistance,maxDistance};
    }
}