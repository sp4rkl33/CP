Problem: https://codeforces.com/contest/1692/problem/H

Tag: Greedy, DP, 1700*

Tutorial:
  - Let break down the problem. 
  - If all elements in the array different as each others the maximum money we can earn is 2^1. Which mean we can only play 1 round with 1 number.
  - Looking ahead, we can see that the correct answer will be the subarray that contains an element with the highest number of appearances relative to the length of the subarray. Your task is to find the subarray that meets all the conditions above and maximizes the number of appearances relative to its length.
  - Define a map which the key is the element and the value is a vector of all the indexes of the key element.
  - For each element's index update the number of win by this formular:

                      win += 2 - elm_idx[i] + elm_idx[i-1]
  - Update the final answer if number of win is greater
  - If number of win is less than 1 we reset the counter to 1 and the left-pointer of the subarray to the current right-pointer.

  - Time complexity: O(N + N * logN).
  - Space complexity: O(N).
