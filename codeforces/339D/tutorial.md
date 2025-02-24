# Problem
https://codeforces.com/contest/339/problem/D <br>
# Tag
data structure, tree, 1700*<br>
# Tutorial
  - Build a segment tree each node [l, r] store the result of XOR or OR of 2 child node.
  - The opeation of merging 2 childs node will alternate from XOR to OR depend on N.
  - We can start from root then traverse though layer and alternate the operator of each layer. <br>
  > the operator of the root will depend on N.
  > N = 1 -> OR
  > N = 2 -> XOR
  > .
  > .
  > . 
  > we can conclude that if N odd the operation will start from OR and opposite with even it will start with XOR.

