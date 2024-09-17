# Set Mismatch

## Problem Description:
You are given a list of integers from 1 to `n`. One integer appears twice, and one integer is missing. Find the duplicate number and the missing number from the list.

## Approach:
1. Use an unordered set to track the numbers that appear in the list.
2. Identify the duplicate number by checking if a number already exists in the set.
3. Then, find the missing number by checking which integer from 1 to `n` is not present in the set.

## Time Complexity:
- **Time Complexity**: O(n), where `n` is the size of the list.
- **Space Complexity**: O(n), as we are using an unordered set to store the numbers.

## Problem Link:
[LeetCode Problem - Set Mismatch](https://leetcode.com/problems/set-mismatch/)
