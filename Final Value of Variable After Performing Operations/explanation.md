## Final Value of Variable After Performing Operations
- **Problem**: Given an array of strings `operations` where each string is either `"X++"`, `"++X"`, `"X--"`, or `"--X"`, perform each operation on an initial variable `X` initialized to 0. Return the final value of `X`.
- **Approach**: 
  Traverse the operations array and increment or decrement the variable `X` based on the operation. Specifically, increase `X` if the operation is `"X++"` or `"++X"`, and decrease `X` if the operation is `"X--"` or `"--X"`.
- **Time Complexity**: O(n), where n is the number of operations.
- **Space Complexity**: O(1), as it uses a constant amount of extra space.
- **LeetCode Link**: [Final Value of Variable After Performing Operations](https://leetcode.com/problems/final-value-of-variable-after-performing-operations/)
