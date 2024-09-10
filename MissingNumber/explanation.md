## Missing Number
- **Problem**: Find the missing number in an array of size `n` that contains distinct numbers from 0 to `n`.
- **Approach**: 
  Used the XOR approach to find the missing number. The idea is to XOR all numbers from 0 to `n` with all the numbers in the array. The missing number will be the result of this XOR operation.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **LeetCode Link**: [Missing Number](https://leetcode.com/problems/missing-number/)
