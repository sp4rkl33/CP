# Problem:
https://codeforces.com/contest/1703/problem/G

# Tag:
1600*, greedy, math

# Tutorial:
  - We'll prove that the optimal solution always be the sum of prefix of good key and suffix of bad key.
```blue
      + If we decide to use the bad key first
          coin = a[i] / 2 + a[i + 1] / 2 - k (*)
      + If we decide to use the good key first
          coin = a[i] + a[i + 1] / 2 - k (**)
```
  - We can easily see that (**) will always greater than (*) in any condition
  - With the limitation of a[i] is 1e9 < 2^31 we can brute force a suffix table of bad keys in time limit then just calculate the optimal answer through all cases.

Time complexity: O(30 * N)<br>
Space complexity: O(30 * N)
