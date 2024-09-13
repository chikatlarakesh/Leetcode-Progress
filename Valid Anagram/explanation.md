## Valid Anagram

- **Problem**: Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise. An anagram is a word or phrase formed by rearranging the letters of a different word or phrase.

- **Approach**:  
  1. First, check if the lengths of the two strings are the same. If not, return `false`.
  2. Sort both strings and compare them. If both sorted strings are equal, return `true`; otherwise, return `false`.

- **Time Complexity**: O(n log n), where `n` is the length of the strings due to sorting.
- **Space Complexity**: O(n), where `n` is the space used for storing the sorted strings.

- **LeetCode Link**: [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
