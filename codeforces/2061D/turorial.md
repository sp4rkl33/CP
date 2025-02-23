Problem: https://codeforces.com/contest/2061/problem/D

Tag: *1600, data structure.

Tutorial:
  - Let's do it backward. We gonna seperate all numbers in array b then match it with number in array a.
  - We'll separate the number until we reach the number 0 then just output "NO"
  - Time complexity: O(mlog(n + m))
  - Space complexity: O(n + m)

** Special case ** 
  - After separate all numbers in b array we have to check if there any number left in a to output the correct answer.


