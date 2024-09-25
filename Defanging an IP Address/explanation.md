# Problem Name: Defanging an IP Address

## Problem Description:
You are given a valid IPv4 address as a string. You need to replace every period `.` in the address with `[.]` and return the modified string.

## Approach:
1. Traverse each character of the string.
2. For each period `.` encountered, append `[.]` to the result string.
3. For any other character, simply append it to the result string.
4. Return the newly constructed string.

## Time Complexity:
The time complexity is O(n), where `n` is the length of the input string, as each character is processed once.

## Space Complexity:
The space complexity is O(n), as we are constructing a new string to store the result.

## Problem Link:
[Defanging an IP Address](https://leetcode.com/problems/defanging-an-ip-address/)
