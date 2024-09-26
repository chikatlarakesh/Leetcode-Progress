# Problem Name: Search in Rotated Sorted Array II

## Problem Description:
You are given an array of integers `nums` sorted in ascending order, which is rotated at some unknown pivot. You need to search for a target value in the array. The array may contain duplicates.

Write a function that returns `true` if the target exists in the array and `false` otherwise.

## Approach:
1. Use a binary search approach with two pointers, `low` and `high`.
2. Calculate the middle index `mid` and compare `nums[mid]` with the target.
3. If `nums[low] == nums[mid] == nums[high]`, increment `low` and decrement `high` to skip duplicates.
4. Determine if the left or right half is sorted and adjust pointers accordingly based on the target's location.
5. Continue the binary search until the target is found or the search space is exhausted.

## Time Complexity:
The time complexity is O(log n) in the average case, but it can degrade to O(n) in the worst case due to the presence of duplicates.

## Space Complexity:
The space complexity is O(1), as we are using only a few extra variables.

## Problem Link:
[Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
