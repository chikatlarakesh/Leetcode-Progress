## Second Largest Digit in a String
- **Problem**: Given a string `s`, return the second largest numerical digit in the string. If no such digit exists, return `-1`.
- **Approach**: 
  1. Traverse through each character in the string and check if it is a digit.
  2. Track the largest and second-largest digits encountered while iterating through the string.
  3. Update the second-largest digit only if it is smaller than the largest and greater than the current second-largest.
- **Time Complexity**: O(n), where `n` is the length of the string.
- **Space Complexity**: O(1), as only a few variables are used to track the largest and second-largest digits.
- **LeetCode Link**: [Second Largest Digit in a String](https://leetcode.com/problems/second-largest-digit-in-a-string/)
