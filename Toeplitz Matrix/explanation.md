## Toeplitz Matrix

- **Problem**: A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element. Given an `m x n` matrix, return `true` if the matrix is Toeplitz, otherwise return `false`.
- **Approach**: 
  - Implemented a helper function `isValid` to check if all elements in a diagonal are the same.
  - The main function iterates over diagonals starting from the first row and first column.
- **Time Complexity**: O(m * n), where `m` is the number of rows and `n` is the number of columns.
- **Space Complexity**: O(1), using constant extra space.
- **LeetCode Link**: [Toeplitz Matrix](https://leetcode.com/problems/toeplitz-matrix/)
