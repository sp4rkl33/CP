Problem: https://codeforces.com/contest/2041/problem/D

Tag: Graphs, Shortest paths, 1700*.

Tutorial:
  - To find the shortest path from S to T we gonna apply dijkstra the minimal node in the heap will be defined as the shortest path from S to some vertex u with the least consecutive move of the lastest direction. By doing this we add an additional state of the direction for distance vector. For example d[v][0] will be the shortest path from S to v with the lastest direction is DOWN.

  - Time complexity: O((n + m) * log(n + m));
  - Space complexity: O(4 * n * m);
