## Majority Element
- **Problem**: Given an array `nums` of size `n`, find the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
- **Approach**: 
  Implemented the Boyer-Moore Voting Algorithm to find the majority element. This algorithm maintains a count of the current candidate for majority and adjusts the count based on whether the candidate matches the current element.
- **Time Complexity**: O(n), where n is the size of the array.
- **Space Complexity**: O(1), as it uses a constant amount of extra space.
- **LeetCode Link**: [Majority Element](https://leetcode.com/problems/majority-element/)
