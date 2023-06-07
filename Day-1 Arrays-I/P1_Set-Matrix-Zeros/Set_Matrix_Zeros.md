
<!-- Heading -->
<h1> Set Matrix Zeroes </h1>

<!-- Difficulty -->
<p style="color: rgb(255 192 30);background: rgba(255, 192, 30, 0.3); padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem;border-radius: 21px; display: inline;">Medium</p>

<br>

<!-- Problem Statement -->
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it [in place](https://en.wikipedia.org/wiki/In-place_algorithm).

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

![Image](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)
<pre>
<strong>Input:</strong> matrix = [[1,1,1],[1,0,1],[1,1,1]]
<strong>Output:</strong> [[1,0,1],[0,0,0],[1,0,1]]
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

![Image](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)
<pre>
<strong>Input:</strong> matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
<strong>Output:</strong> [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
</pre>

<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-231 <= matrix[i][j] <= 231 - 1`

<strong>Follow up:</strong>

- A straightforward solution using `O(mn)` space is probably a bad idea.
- A simple improvement uses `O(m + n)` space, but still not the best solution.
- Could you devise a constant space solution?

<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)
- [Leetcode](https://leetcode.com/problems/set-matrix-zeroes/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://youtu.be/N0MgLvceX7M)
- [TUF Article](https://takeuforward.org/data-structure/set-matrix-zero/)