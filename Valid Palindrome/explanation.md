## Valid Palindrome
- **Problem**: Given a string `s`, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
- **Approach**: 
  1. **Filter and Normalize**: Traverse the string, appending only alphanumeric characters in lowercase to a new string `r`.
  2. **Check Palindrome**: Compare the string `r` with its reverse to determine if it is a palindrome.
- **Time Complexity**: O(n), where n is the length of the string.
- **Space Complexity**: O(n), for storing the filtered and normalized string.
- **LeetCode Link**: [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
