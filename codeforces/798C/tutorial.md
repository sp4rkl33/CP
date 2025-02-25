# Problem
https://codeforces.com/problemset/problem/798/C
# Tag
dp, greedy, 1700*
# Tutorial (Greedy Approach)
  - Firstly the answer will always be yes because it always possible to make gcd(B) > 1 when A always have more than 2 numbers.
  - It easy to regconize that if we can make all the number in the array to even the gcd(B) >= 2
  - There 2 cases:
      + If you merge 2 odd number it will take 1 step.
      + If you merge 1 odd and 1 even it will take 2 step.
  


Time complexity: O(n * log(max(a[i]))<br>
Space complexity: O(n) for DP, O(1) for greedy.
