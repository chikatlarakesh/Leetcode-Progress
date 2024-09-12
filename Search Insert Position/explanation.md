## Search Insert Position

- **Problem**: Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
  
- **Approach**: 
  - We use binary search to find the target efficiently. 
  - Start with two pointers, `low` and `high`, and calculate the midpoint.
  - If the target is found, return the index.
  - If the target is greater than the middle element, adjust `low`; if it's smaller, adjust `high`.
  - If the target is not found, return the index where it should be inserted.
  
- **Time Complexity**: O(log n), where `n` is the size of the array (due to binary search).
  
- **Space Complexity**: O(1) (constant space).
  
- **LeetCode Link**: [Search Insert Position](https://leetcode.com/problems/search-insert-position/)
