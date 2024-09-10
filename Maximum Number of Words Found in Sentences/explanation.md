## Maximum Number of Words Found in Sentences
- **Problem**: Given a list of sentences, each sentence is a string of words separated by spaces. Return the maximum number of words that can be found in any single sentence.
- **Approach**: 
  1. Iterate through each sentence and count the number of spaces to determine the number of words in the sentence (the number of words is one more than the number of spaces).
  2. Keep track of the maximum number of words found in any sentence.
- **Time Complexity**: O(n * m), where `n` is the number of sentences and `m` is the average length of each sentence.
- **Space Complexity**: O(1), as we only use a few variables for counting.
- **LeetCode Link**: [Maximum Number of Words Found in Sentences](https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/)
