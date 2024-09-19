# Problem Name: Search a 2D Matrix

## Problem Description:
You are given a matrix of integers where each row is sorted in ascending order and each column is also sorted in ascending order. Your task is to determine if a target value exists in the matrix.

## Approach:
1. Start from the top-right corner of the matrix.
2. If the current element is equal to the target, return `true`.
3. If the current element is less than the target, move downwards to the next row.
4. If the current element is greater than the target, move left to the previous column.
5. Continue this process until you either find the target or exhaust the search area.

## Time Complexity:
Time complexity is O(m + n), where m is the number of rows and n is the number of columns. This is because each step either decreases the row index or the column index by one.

## Space Complexity:
Space complexity is O(1) as we are using only a constant amount of extra space.

## Problem Link:
[Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)
