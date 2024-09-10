## Best Time to Buy and Sell Stock
- **Problem**: Given an array `prices` where `prices[i]` is the price of a given stock on the ith day, find the maximum profit you can achieve by buying and then selling the stock. You can only complete one transaction (buy one and sell one).
- **Approach**: 
  Traverse the array while keeping track of the minimum price encountered so far and the maximum profit achievable. For each day, calculate the potential profit from buying at the minimum price and selling on that day. Update the maximum profit if the calculated profit is higher. Update the minimum price if the current price is lower.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **LeetCode Link**: [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
