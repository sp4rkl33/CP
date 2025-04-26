# Problem:
https://codeforces.com/contest/339/problem/D

# Tag:
data structure, 2200*

# Tutorial:
Build a segment tree each node store 3 things:
    + The number of open bracket that haven't been used (free_open)
    + The number of close bracket that haven't been used (free_close)
    + The number of correct of pair brackets.
    
Calculate each elements of current node like this (set 0 for all variables):
'''
    Step 1:
    correct_cur = min(left_free_open, right_free_close) + correct_left + correct_right

    Step 2:
    If left_free_open > right_free_close:
    cur_free_open = left_free_open - right_free_close
    Else do it otherwise.

    *Step 3:
        + cur_free_open += right_free_open
        + cur_free_close += left_free_close
'''
For each queries just take the node which in range [l, r] and do the calculation like previous step.

  - Time complexity: O((N + Q) * log(N)) <br>
  - Space complexity: O(n);
