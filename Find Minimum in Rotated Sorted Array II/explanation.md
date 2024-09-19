# Problem Name: Find Minimum in Rotated Sorted Array II

## Problem Description:
You are given a sorted and rotated array where some of the elements may be duplicates. Your task is to find the minimum element in this array. The array has been rotated between 1 and n times and may contain duplicate values.

## Approach:
1. Use binary search to narrow down the search space for the minimum element.
2. If the middle element is less than or equal to the right boundary, the minimum must lie on the left side.
3. If the middle element is greater than the right boundary, the minimum must lie on the right side.
4. Handle cases where duplicates are present by adjusting the low and high boundaries accordingly.
5. Keep updating the minimum as you traverse through the array.

## Time Complexity:
Time complexity is O(log n) in the average case. In the worst case, due to duplicates, it can degrade to O(n).

## Space Complexity:
Space complexity is O(1) as we are using constant space for binary search.

## Problem Link:
[Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)
