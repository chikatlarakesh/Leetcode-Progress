## Find First and Last Position of Element in Sorted Array
- **Problem**: Given a sorted array `nums` and a target value, return the first and last position of the target in the array. If the target is not found, return `[-1, -1]`.
- **Approach**: 
  1. Iterate through the array and look for the target.
  2. When the target is found for the first time, store its index as the starting position.
  3. Continue iterating to update the ending position as the index of the last occurrence of the target.
  4. If the target is not found at all, return `[-1, -1]`.
- **Time Complexity**: O(n), where `n` is the size of the array.
- **Space Complexity**: O(1), as no additional space other than variables is used.
- **LeetCode Link**: [Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
