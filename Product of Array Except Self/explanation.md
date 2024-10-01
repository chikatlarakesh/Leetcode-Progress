### Problem Name: Product of Array Except Self

#### Problem Description:

Given an array `nums` of length `n`, return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`. You must solve it without using division and in O(n) time complexity.

#### Approach:

1. Traverse the array to calculate the total product of non-zero elements and count the number of zeros in the array.
2. Create a second traversal to build the output array:
   - If there are no zeros, each element in the output is the total product divided by the corresponding element in `nums`.
   - If there is one zero, the output at the index of the zero is the total product, and all other indices are set to zero.
   - If there are two or more zeros, all outputs are set to zero.

#### Time Complexity:

The time complexity is O(n) since we traverse the array a constant number of times.

#### Space Complexity:

The space complexity is O(1) if we consider the output array as part of the input, otherwise O(n) for the output array.

#### Problem Link:

[Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
