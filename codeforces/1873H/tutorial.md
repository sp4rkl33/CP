Problem: https://codeforces.com/contest/1873/problem/H

Tag: 1700*, DFS - BFS

Tutorial:
  - Observing that V (Valeriu) could escape from M (Marcel) if V reach the closet cycle before M then V just go aound the cycle and M will never reach him.
  - We'll run DFS from V until we found a vertex v that have been visit and it must not a child of u.
  - Finally we'll run 2 BFS one from V and one from M to find the smallest distance from it initial position to v. Valeriu win if he reach v first.

 Time complexity: O(n).
 Space complexity: O(n).
