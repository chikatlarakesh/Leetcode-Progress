## Plus One

- **Problem**: Given a non-negative integer represented as a list of digits, add one to the integer. The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
  
- **Approach**: 
  - Start from the last digit and check if it's less than 9. If so, increment it and return the updated list.
  - If the digit is 9, set it to 0 and move to the previous digit.
  - If all digits are 9, insert 1 at the beginning of the list.

- **Time Complexity**: O(n), where `n` is the number of digits.
  
- **Space Complexity**: O(1) (ignoring input/output space).

- **LeetCode Link**: [Plus One](https://leetcode.com/problems/plus-one/)
