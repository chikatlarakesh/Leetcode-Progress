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
        int index = 1;
        int currCriticalPoint = -1, prevCriticalPoint = -1;
        int minDistance = Integer.MAX_VALUE;
        int minCriticalPoint = Integer.MAX_VALUE;
        int maxCriticalPoint = 0;

        while(curr.next != null) {
            ListNode right = curr.next;
            if((curr.val > left.val && curr.val > right.val) || 
                (curr.val < left.val && curr.val < right.val)) {
                    minCriticalPoint = Math.min(minCriticalPoint,index);
                    maxCriticalPoint = Math.max(maxCriticalPoint,index);

                    if(currCriticalPoint == -1) currCriticalPoint = index;
                    else {
                        prevCriticalPoint = currCriticalPoint;
                        currCriticalPoint = index;
                        minDistance = Math.min(minDistance,currCriticalPoint - prevCriticalPoint);
                    }
                }
            left = curr;
            curr = curr.next;
            index++;
        }

        if(prevCriticalPoint == -1) return new int[]{-1,-1};

        int maxDistance = maxCriticalPoint - minCriticalPoint;
        return new int[]{minDistance,maxDistance};








        // ListNode left = head;
        // ListNode curr = head.next;
        // List<Integer> criticalPoints = new ArrayList<>();
        // int index = 1;

        // while(curr.next != null) {
        //     ListNode right = curr.next;
        //     if((curr.val > left.val && curr.val > right.val) || 
        //         (curr.val < left.val && curr.val < right.val)) {
        //             criticalPoints.add(index);
        //         }
            
        //     left = curr;
        //     curr = curr.next;
        //     index++;
        // }

        // int n = criticalPoints.size();
        // if(n <= 1) return new int[]{-1,-1};

        // int maxDistance = criticalPoints.get(n-1) - criticalPoints.get(0);

        // int minDistance = Integer.MAX_VALUE;
        // for(int i=1;i<n;i++) {
        //     minDistance = Math.min(minDistance,criticalPoints.get(i) - criticalPoints.get(i-1));
        // } 
        // return new int[]{minDistance,maxDistance};
    }
}