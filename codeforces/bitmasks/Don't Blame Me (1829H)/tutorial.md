# Problem
https://codeforces.com/contest/1829/problem/H

# Tag:
bitmasks, dp, 1700*

# Tutorial:
  - Because a[i] is very small <= 63 so we can count all subsequences that AND value is equal to x (0 <= x <= 63)
  - Using dynamic programming. Define f[i][j] is number of subsequences end with a[i] and have AND value equal to j
  - We have 3 cases:
    ```
      + If we skip a[i] then just update f[i][j] in the following way:
          f[i][j] = f[i][j] + f[i - 1][j]
      + If we take a[i]:
          f[i][a[i] & j] = f[i][a[i] & j] + f[i - 1][j]
      + If a[i] is the start element of a subsequence:
          f[i][a[i]] + f[i][a[i]] + 1
    ```
  - At the end just sum every cases that have k set bits in binary presentation of x (0 <= x <= 63)

Time complexity: O(63 * N)<br>
Space complexity: O(63 * N)
