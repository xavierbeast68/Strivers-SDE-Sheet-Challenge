
<!-- Heading -->
<h1>Unique Paths</h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Medium</p>

<br>

<!-- Problem Statement -->
There is a robot on an <code>m x n</code> grid. The robot is initially located at the top-left corner (i.e., <code>grid[0][0]</code>). The robot tries to move to the bottom-right corner (i.e., <code>grid[m - 1][n - 1]</code>). The robot can only move either down or right at any point in time.

Given the two integers <code>m</code> and <code>n</code>, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to <code>2 * 10<sup>9</sup></code>.

<!-- line break -->
<p>&nbsp</p>


<!-- example 1 -->
<strong>Example 1:</strong>

![Image](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

<pre>
<strong>Input:</strong> m = 3, n = 7
<strong>Output:</strong> 28
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

<pre>
<strong>Input:</strong> m = 3, n = 2
<strong>Output:</strong> 3
<strong>Explanation:</strong> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>1 <= m, n <= 100</code></p>


<!-- line break -->
<p>&nbsp</p>

<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470)
- [Leetcode](https://leetcode.com/problems/unique-paths/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://www.youtube.com/watch?v=t_f0nwwdg5o)
- [Striver's Video 2 (using DP)](https://youtu.be/sdE0A2Oxofw)
- [TUF Article](https://takeuforward.org/data-structure/grid-unique-paths-count-paths-from-left-top-to-the-right-bottom-of-a-matrix/)