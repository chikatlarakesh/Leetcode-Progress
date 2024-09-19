# Problem Name: Decode the Message

## Problem Description:
You are given the key and message. The key is a string consisting of letters and spaces, and you need to decode the message by mapping the characters in the key to a simplified alphabet. The message is decoded using this mapping.

## Approach:
1. Create a map to store the mapping from the characters in the key to the alphabet (a to z).
2. Traverse the key and for each unique non-space character, map it to the next available letter in the alphabet.
3. For decoding the message, replace each character in the message using the mapping created from the key.
4. Maintain spaces in the message while decoding.

## Time Complexity:
Time complexity is O(n), where n is the length of the key and message combined. Each character in the key and message is processed once.

## Space Complexity:
Space complexity is O(1), considering that we are only mapping 26 lowercase letters.

## Problem Link:
[Decode the Message](https://leetcode.com/problems/decode-the-message/)
