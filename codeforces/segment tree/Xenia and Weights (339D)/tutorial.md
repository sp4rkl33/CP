# Problem
https://codeforces.com/contest/339/problem/D <br>
# Tag
data structure, tree, 1700*<br>
# Tutorial
  - Build a segment tree each node [l, r] store the result of XOR or OR of 2 child node.
  - The opeation of merging 2 childs node will alternate from XOR to OR depend on where is node level.
  - We can start from root then traverse though layer and alternate the operator of each layer. <br>
  > the operator of the root will depend on N. <br>
  > N = 1 -> OR <br>
  > N = 2 -> XOR <br>
  > . <br>
  > . <br>
  > . <br>
  > we can conclude that if N odd the operation will start from OR and opposite with even it will start with XOR. <br>
  - For each query we dont have to re-build the whole tree. Just find a path to the position P by squezze the range and update all node on the path we met.

Time complexity: O(((2 ^ n) + m) * n)<br>
Space complexity: O(2 ^ n)
