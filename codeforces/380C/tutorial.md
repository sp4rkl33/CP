# Problem:
https://codeforces.com/contest/339/problem/D

# Tag:
data structure, 2000*

# Tutorial:
Build a segment tree each node store 3 infomation:
  - The number of left bracket that haven't been used (freeL).
  - The number of right bracket that haven't been used (freeR).
  - Number of correct pairs of bracket (cnt).

We can implement node-merging operation like this:
  - Let current node called cur(freeL, freeR, cnt). We can calculate current node like this:
> t = min(left.freeL, right.freeR) <br>
> cur.freeL = left.freeL - t + right.freeL <br>
> cur.freeR = left.freeR + right.freeR - t <br>
> cur.cnt = t + left.cnt + right.cnt <br>

