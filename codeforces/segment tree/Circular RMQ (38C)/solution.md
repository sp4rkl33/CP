# Problem:
https://codeforces.com/contest/52/problem/C

# Tag:
data structure, 2200*

# Tutorial:
Build a normal min segment tree with lazy tag in the node itself.

While update or querying just do push down the tag of the current node to 2 child node.

The circular query is only happend if L > R and if that happend just do operation of 2 different query:
Query(0 -> R) and Query(L, N - 1)

  - Time complexity: O(Q * log(N)) <br>
  - Space complexity: O(n);
