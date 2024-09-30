### Problem Name: Find All Numbers Disappeared in an Array

#### Problem Description:

Given an array `nums` of size `n` where all integers are in the range `[1, n]`, some elements appear twice, and others appear once. Find all the integers in the range `[1, n]` that do not appear in `nums`.

#### Approach:

1. Insert each number from the input array into an unordered set.
2. Iterate from 1 to `n` and check if each number exists in the set.
3. If a number is missing from the set, add it to the result vector.

#### Time Complexity:

The time complexity is O(n) since we traverse the array once to build the set and then iterate through the numbers again to check for missing elements.

#### Space Complexity:

The space complexity is O(n) due to the space required for the set and the result vector.

#### Problem Link:

[Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
