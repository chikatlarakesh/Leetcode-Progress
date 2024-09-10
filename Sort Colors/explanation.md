## Sort Colors
- **Problem**: Given an array `nums` containing only the integers 0, 1, and 2, sort the array in-place so that all 0s come first, followed by 1s, and then 2s.
- **Approach**: 
  1. Implement a bubble sort algorithm to sort the array. This involves comparing adjacent elements and swapping them if they are in the wrong order.
  2. Track if any swaps are made during each pass. If no swaps occur, the array is already sorted, and you can break out of the loop early.
- **Time Complexity**: O(n^2), where `n` is the number of elements in the array. Bubble sort has a quadratic time complexity in the worst case.
- **Space Complexity**: O(1), as the sorting is done in-place using a few extra variables.
- **LeetCode Link**: [Sort Colors](https://leetcode.com/problems/sort-colors/)
