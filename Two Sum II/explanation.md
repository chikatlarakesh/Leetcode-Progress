# Problem Name: Two Sum II - Input Array Is Sorted

## Problem Description:
You are given an array of integers `numbers` that is sorted in non-decreasing order and a target number `target`. Find two numbers such that they add up to the target. The function should return the indices of the two numbers (1-based index).

## Approach:
1. Use two pointers, `low` and `high`, initialized to the first and last element of the array, respectively.
2. Calculate the sum of `numbers[low]` and `numbers[high]`.
3. If the sum equals the target, return the indices of these two numbers.
4. If the sum is less than the target, increment the `low` pointer.
5. If the sum is greater than the target, decrement the `high` pointer.
6. Continue the process until the solution is found.

## Time Complexity:
The time complexity is O(n), where n is the size of the input array. This is because each element is processed at most once.

## Space Complexity:
The space complexity is O(1), as no extra space is used beyond the input array and result.

## Problem Link:
[Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
