## Jewels and Stones
- **Problem**: You're given two strings `jewels` and `stones`. Each character in `jewels` is a type of stone considered a jewel, and each character in `stones` is a stone you have. You want to know how many of the stones you have are also jewels.
- **Approach**: 
  1. Convert the `jewels` string into an unordered set to enable constant time lookups.
  2. Traverse the `stones` string and check for each stone if it exists in the set of jewels.
  3. Increment the count for each stone found in the set.
- **Time Complexity**: O(m + n), where `m` is the length of the `jewels` string and `n` is the length of the `stones` string.
- **Space Complexity**: O(m), where `m` is the size of the `jewels` set.
- **LeetCode Link**: [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/)
