## Two Furthest Houses With Different Colors
- **Problem**: Given an array `colors`, where each index represents a house and its value is the color of that house, find the maximum distance between two houses that have different colors. The distance between the two houses is the absolute difference between their indices.
- **Approach**: 
  1. The idea is to check two possible distances:
     - The distance from the first house (`colors[0]`) to the farthest house with a different color.
     - The distance from the last house (`colors[n-1]`) to the farthest house with a different color.
  2. Iterate from both the start and end of the array to find the maximum distance where the colors are different.
  3. Return the larger of the two distances.
- **Time Complexity**: O(n), where `n` is the size of the array.
- **Space Complexity**: O(1), as no extra space is used.
- **LeetCode Link**: [Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/)
