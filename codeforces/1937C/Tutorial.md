https://codeforces.com/contest/1937/problem/C

Tags: Interactive, 1600*

Tutorial

Goal: To maximize p[i] ^ p[j] we have to fill all the bit with '1'  

Firstly we'll find the largest p[i] in the permutation and store it into ki with the query "? i i ki ki". 
Then find all p[k] which is p[k] | p[ki] is largest then store it into a vector.
Finally find the smallest p[j] in the vector above then the answer will be i and j.

Prove:
  - Example if the bit sequence of p[i] is "110011" so we have to find p[j] that have the bit sequence is "001100" to 
  maximize p[i] ^ p[j]

  - **BUT** there're many bit sequences that p[i] | p[k] = p[i] ^ p[j]. Because we just have to fill the '0' bits so
  so that we have to find the minimum of all the p[k].

  - Then the answer will be ! i k (which k is the minimum p[k] of all the "p[k]s" in the vector).

  Time complexity: O(n).
  Space complexity: O(n).
