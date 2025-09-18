#Problem:
https://atcoder.jp/contests/practice2/tasks/practice2_k

#Tag:
Data structure, Tree

#Tutorial:
Using lazy segment tree to store segment's value and tag
  - let's S be the sum of some segment [l, r) <br>
        ```
            S = a[l] + a[l + 1] + ... + a[r - 1] 
        ```
  - Then apply the first pair {b, c} into that segment and call the new sum is S2
        ```
           S2 = b * a[l] + c + b * a[l + 1] + c + ... + b * a[r - 1] + c
        ```
        ```
              = b * (a[l] + a[l + 1] + ... + a[r - 1]) + (r - l) * c <br>
        ```
        ```
              = b * S + c * (r - l) (**) <br>
        ```
  - Let's {b, c} become the coefficient of {S, (r - l)} (**).
  - Again apply pair {b1, c1} into the same segment and call the new sum is S3
        ```
           S3 = b1 * (b * a[l] + c) + c1 + ... + b1 * (b * a[r - 1] + c) + c1
              = b1 * S2 + (r - l) + c1
              = b1 * (b * S + (r - l) * c) + (r - l) * c1
              = b1 * b * S + b1 * (r - l) * c + (r - l) * c1
              = b1 * b * S + (b1 * c + c1) * (r - l)
        ```
  - Observing if we continue to apply another pair {bx, cx} into the segment. It will become
        ```
           S4 = bx * b1 * b * S + (bx * (b1 * c + c1) + cx) * (r - l)
        ```
  - By this time we can come up a formula for both the coefficient.
        ```
           Define:
            - coeB: First coefficient 
            - coeC: Second coefficient
            - b: new added
            - c: new added
               => coeB = coeB * b
               => coeC = b * coeC + c
        ```
  - The above infomation is 90% of the problem now just use your own way to implement it with a lazy segment tree.
