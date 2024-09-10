## Length of Last Word
- **Problem**: Given a string `s` consisting of words and spaces, return the length of the last word in the string. A word is defined as a maximal substring consisting of non-space characters only.
- **Approach**: 
  1. Start iterating from the end of the string.
  2. Count the characters of the last word while ignoring trailing spaces.
  3. Once a space is encountered after counting the last word, break the loop.
  4. Return the count of characters in the last word.
- **Time Complexity**: O(n), where `n` is the length of the string.
- **Space Complexity**: O(1), as no extra space is used apart from a few variables.
- **LeetCode Link**: [Length of Last Word](https://leetcode.com/problems/length-of-last-word/)
