# Problem: 
https://codeforces.com/contest/1760/problem/G

# Tag: 
dfs, graph, 1700*

# Tutorial:
  - Let's re-define a valid path. Given a path from A to C with an XOR of all edges equal to x, and another from B to D where the XOR of edges is also x. Then by a single teleportation from C to D we'll have a valid path.
  - We'll DFS from B to all the vertices in the tree and store all the XOR results while traversing into a map.
  - To find valid path we just DFS from A to all vertices (except for B) and while traversing if we find a path have the XOR result equal to x and it's contained in the map it will be the valid path.

# Prove:
  - Given A = X1 ^ X2 ^ X3 ^ ... ^ Xn = Y1 ^ Y2 ^ Y3 ^ ... ^ Yn and A ^ A = 0
  - So that X1 ^ X2 ^ X3 ^ ... ^ Xn ^ Y1 ^ Y2 ^ Y3 ^ ... ^ Yn = A ^ A = 0

Time complexity: O(n * log(n)) <br>
Space complexity: O(n)
