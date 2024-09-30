### Problem Name: Count Substrings with Exactly 3 Distinct Characters

#### Problem Description:

Given a string `s`, find the number of substrings of length 3 that consist of distinct characters. Return the count of such substrings.

#### Approach:

1. Use a sliding window technique with two pointers, `l` and `r`, to keep track of a window of length 3.
2. Use a map to track the frequency of characters in the current window.
3. If the window contains exactly 3 distinct characters, increase the result count.
4. Slide the window by moving the left pointer and update the map accordingly.
5. Repeat the process until the end of the string is reached.

#### Time Complexity:

The time complexity is O(n), where `n` is the length of the string, as each character is processed only once.

#### Space Complexity:

The space complexity is O(1) because the map will only ever contain a maximum of 3 characters.

#### Problem Link:

[Count Substrings with Exactly 3 Distinct Characters](https://leetcode.com/problems/count-substrings-with-exactly-3-distinct-characters/)
