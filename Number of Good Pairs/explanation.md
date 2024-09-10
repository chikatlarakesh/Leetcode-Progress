## Number of Good Pairs
- **Problem**: Given an array `nums` of integers, find the number of good pairs `(i, j)` where `0 <= i < j < nums.length` and `nums[i] == nums[j]`.
- **Approach**: 
  1. Use an unordered map to keep track of the count of each number as you iterate through the array.
  2. For each number, if it has been seen before, the count of good pairs is incremented by the number of times this number has been seen before (because each previous occurrence forms a good pair with the current index).
  3. Update the map with the current number.
- **Time Complexity**: O(n), where `n` is the size of the array. Each lookup and insertion in the unordered map is O(1) on average.
- **Space Complexity**: O(n), due to the space required for the unordered map.
- **LeetCode Link**: [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/)
