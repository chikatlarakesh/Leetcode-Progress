# Problem Name: Search in Rotated Sorted Array

## Problem Description:
Given an array of integers `nums` sorted in ascending order (but rotated at an unknown pivot), and an integer `target`, find the index of `target` in the array. If `target` is not found, return -1.

## Approach:
1. Perform a binary search by maintaining `low` and `high` pointers.
2. Find the middle element and check if it is the target.
3. If the left half is sorted (`nums[low] <= nums[mid]`), check if the target lies within this range:
   - If yes, reduce the search space to the left half.
   - Otherwise, search in the right half.
4. If the right half is sorted, repeat the same check for the target's range.
5. Continue narrowing the search space until the target is found or the search space is exhausted.

## Time Complexity:
The time complexity is O(log n), where `n` is the number of elements in the array, due to the binary search approach.

## Space Complexity:
The space complexity is O(1), as no extra space is used beyond the input array.

## Problem Link:
[Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
