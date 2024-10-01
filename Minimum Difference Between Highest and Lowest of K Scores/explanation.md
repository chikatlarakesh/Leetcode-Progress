### Problem Name: Minimum Difference Between Highest and Lowest of K Scores

#### Problem Description:

Given an array `nums` representing the scores of students, and an integer `k`, select `k` scores from the array such that the difference between the highest and the lowest score is minimized.

#### Approach:

1. Sort the array to ensure that for any valid subarray of size `k`, the difference between the maximum and minimum is minimized.
2. Use a sliding window technique to check every possible subarray of size `k`. Calculate the difference between the last and first element in each subarray.
3. Update the result with the minimum difference encountered.

#### Time Complexity:

The time complexity is O(n log n) due to the sorting step, where `n` is the length of the input array.

#### Space Complexity:

The space complexity is O(1) as the sorting is done in place, and no additional space is used beyond constant space.

#### Problem Link:

[Minimum Difference Between Highest and Lowest of K Scores](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/)
