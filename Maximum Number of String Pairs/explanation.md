## Maximum Number of String Pairs
- **Problem**: Given a list of strings `words`, find the number of pairs `(i, j)` where `i < j` and `words[i]` is equal to the reverse of `words[j]`.
- **Approach**: 
  1. Use a nested loop to check each pair of strings in the list.
  2. For each pair `(i, j)`, reverse the second string and compare it with the first string.
  3. If the first string is equal to the reversed second string, increment the count.
- **Time Complexity**: O(n^2 * m), where `n` is the number of strings and `m` is the average length of the strings.
- **Space Complexity**: O(m), for storing the reversed string.
- **LeetCode Link**: [Maximum Number of String Pairs](https://leetcode.com/problems/maximum-number-of-string-pairs/)
