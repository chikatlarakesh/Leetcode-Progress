# Problem Name: Find Peak Element

## Problem Description:
You need to find a peak element in an array where an element is considered a peak if it is greater than its neighbors. For the array edge elements, they are considered peaks if they are greater than their single neighbor.

## Approach:
1. Check if the array contains only one element. If so, return 0 as it is the peak.
2. Check if the first element is greater than the second element. If true, return 0.
3. Check if the last element is greater than the second last element. If true, return the last index.
4. Traverse the array from index 1 to `n-2`:
   - For each element, check if it is greater than both its neighbors.
   - If true, return the index of that element.
5. If no peak is found, return -1.

## Time Complexity:
Time complexity is O(n), where n is the number of elements in the array. We traverse the array once to find the peak.

## Space Complexity:
Space complexity is O(1) as we are using only a constant amount of extra space.

## Problem Link:
[Find Peak Element](https://leetcode.com/problems/find-peak-element/)
