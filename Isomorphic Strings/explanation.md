# Problem Name: Isomorphic Strings

## Problem Description:
Given two strings `s` and `t`, determine if they are isomorphic. Two strings are isomorphic if the characters in `s` can be replaced to get `t`. All occurrences of a character must be replaced with another character while preserving the order of characters.

## Approach:
1. Use two maps:
   - `m1` to map characters from string `s` to string `t`.
   - `m2` to map characters from string `t` to string `s`.
2. Traverse both strings simultaneously:
   - For each character, check if it already exists in the respective map.
   - If a mapping does not exist, create a new mapping between the characters from `s` to `t` and vice versa.
   - If a mapping exists but does not match, return `false`.
3. If all characters match correctly, return `true`.

## Time Complexity:
The time complexity is O(n), where `n` is the length of the strings. Each character is processed once.

## Space Complexity:
The space complexity is O(1), since the number of characters we map is limited to 26 English letters.

## Problem Link:
[Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)
