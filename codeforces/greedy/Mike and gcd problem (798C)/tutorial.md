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
  - Using a counter or two pointer to find all consecutive subarrays that consist exclusively of odd numbers and calculate the minimum step of operation based on its length then add to the answer.

# DP Approach:
  - We define f[i] is the minimum step to make the GCD of the first i's number greater than 1.
  - We also have an additional state array defined how is the number we merge with (only for odds). We can define like:
  ```
  state[i] = 0 which mean this is a free odd
  state[i] = 1 which mean this currently merge with an even number
  state[i] = 2 which mean this currently merge with an odd one (which is this was minimal and we can consider it like an even num).
  ```
  - Iterate through the array and when we meet an odd number just base on the previous number state then calculate the minimum step for the current f[i].<br>
  - **If a[1] is an odd number we can consider it is merged with an even one then set f[1] = 2 and state[1] = 2.** <br>

**Special case: if gcd(A) already greater than 1 we just print 0 to the step output**  

Time complexity: O(n * log(2 * max(a[i]))<br>
Space complexity: O(n) for DP, O(1) for greedy.
