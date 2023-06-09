
<!-- Heading -->
<h1> Search a 2D Matrix </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Medium</p>

<br>

<!-- Problem Statement -->
You are given an <code>m x n</code> integer matrix <code>matrix</code> with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.
Given an integer <code>target</code>, return <code>true</code> if target is in matrix or false otherwise.

You must write a solution in <code>O(log(m * n))</code> time complexity.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>

![image](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>Output:</strong> true
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

![image](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)
<pre>
<strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>Output:</strong> false
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>m == matrix.length</code></p>
- <p><code>n == matrix[i].length</code></p>
- <p><code>1 <= m, n <= 100</code></p>
- <p><code>-10<sup>4</sup> <= matrix[i][j], target <= 10<sup>4</sup></code></p>


<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531)
- [Leetcode](https://leetcode.com/problems/search-a-2d-matrix/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://www.youtube.com/watch?v=ZYpYur0znng)
- [TUF Article](https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/)