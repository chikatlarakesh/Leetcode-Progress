# Problem Name: Two Sum

## Problem Description:
Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to the `target`. You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Approach:
1. Create an empty unordered map to store the index of each element as you iterate through the array.
2. Traverse the array `nums`:
   - For each element, check if the difference between the `target` and the current element exists in the map.
   - If found, the current element and the stored element form the required pair.
   - If not, add the current element and its index to the map.
3. Return the indices of the two numbers that sum to `target`.

## Time Complexity:
Time complexity is O(n), where `n` is the number of elements in the array. Each element is processed once.

## Space Complexity:
Space complexity is O(n), as we store the indices of the elements in a hash map.

## Problem Link:
[Two Sum](https://leetcode.com/problems/two-sum/)
