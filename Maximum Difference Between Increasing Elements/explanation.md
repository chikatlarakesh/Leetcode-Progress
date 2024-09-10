## Maximum Difference Between Increasing Elements
- **Problem**: Given an array `nums`, find the maximum difference between `nums[j] - nums[i]` such that `j > i` and `nums[j] > nums[i]`. If no such elements exist, return `-1`.
- **Approach**: 
  1. Initialize the first element as the minimum (low).
  2. Iterate through the array, updating the maximum difference if the current element minus the minimum is greater than the previously found difference.
  3. Update the minimum value when encountering a smaller element to ensure `j > i` for valid pairs.
  4. If no valid difference is found, return `-1`.
- **Time Complexity**: O(n), where `n` is the size of the array.
- **Space Complexity**: O(1), as only a few variables are used.
- **LeetCode Link**: [Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)
