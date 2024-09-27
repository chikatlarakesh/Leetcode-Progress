# Problem Name: Single Number II

## Problem Description:
You are given an integer array `nums` where every element appears three times except for one, which appears exactly once. You need to find and return the single element that appears only once.

## Approach:
1. Use an unordered map to store the frequency of each number in the array.
2. Traverse the array and update the map with the count of each element.
3. After the frequency map is built, traverse the map to find the element that has a frequency of one.
4. Return the element that appears only once.

## Time Complexity:
The time complexity is O(n), where n is the size of the input array. This is because we traverse the array twice: once for counting and once for finding the single number.

## Space Complexity:
The space complexity is O(n), as we use an unordered map to store the frequency of elements.

## Problem Link:
[Single Number II](https://leetcode.com/problems/single-number-ii/)
