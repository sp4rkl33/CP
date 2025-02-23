Problem: https://codeforces.com/contest/1822/problem/F

Tag: DFS, Tree, 1700*

Before getting into the tutorial we'll have a definition:
  - We call d(A, B) is the shortest distance from node A to node B of the tree. By maximize the d(A, B) it became the diameter of the tree called diam(A, B), A and B is two end points of diam(A, B).
  - To find A and B:
      + Run DFS from any node X and mark the farthest node Y from X. Y will be A
      + Then simply just run DFS from node A and mark the farthest node B. The distance from A to B will be the diameter of the tree and A and B will be two end points.

Tutorial:
  - Suppose we have A and B are two end points of the tree. We can find A by run DFS from root and find B by DFS from A.
  - While traversing we store the distances from each nodes root, A, B into three different arrays:
      + disR: distance from root to all nodes in tree.
      + disA: distance from A to all nodes in tree.
      + disB: distance from B to all nodes in tree.
  - Finally just calculate the ans by try to shift the root through all node and from current shifted node to farthest node. Because we had stored all the information earlier we can managed to calculate the answer in O(1).

        For example if we shift root to node u:
        ans = max(ans, max(disA[u], disB[u]) * k - disR[u] * c)

  - Time complexity: O(n)
  - Space complexity: O(n)
