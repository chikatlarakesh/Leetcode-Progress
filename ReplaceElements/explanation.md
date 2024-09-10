## Replace Elements with Greatest Element on Right Side
- **Problem**: Given an array `arr`, replace each element with the greatest element on its right side. The last element should be replaced with `-1`.
- **Approach**: 
  Traverse the array from right to left, keeping track of the maximum element encountered so far. Replace each element with this maximum, then update the maximum if the current element is greater.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **LeetCode Link**: [Replace Elements with Greatest Element on Right Side](https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/)
