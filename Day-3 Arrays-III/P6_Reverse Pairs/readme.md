
<!-- Heading -->
<h1>Reverse Pairs
</h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Hard</p>

<br>

<!-- Problem Statement -->
Given an integer array <code>nums</code>, return the number of reverse pairs in the array.

A reverse pair is a pair <code>(i, j)</code> where:

- <code>0 <= i < j < nums.length</code> and
- <code>nums[i] > 2 * nums[j]</code>.

<!-- line break -->
<p>&nbsp</p>


<!-- example 1 -->
<strong>Example 1:</strong>

<pre>
<strong>Input:</strong> nums = [1,3,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>

<pre>
<strong>Input:</strong> nums = [2,4,3,5,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>1 <= nums.length <= 5 * 10<sup>4</sup></code></p>
- <p><code>-2<sup>31</sup> <= nums[i] <= 2<sup>31</sup>-1</code></p>


<!-- line break -->
<p>&nbsp</p>

<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/reverse-pairs_1112652)
- [Leetcode](https://leetcode.com/problems/reverse-pairs/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://www.youtube.com/watch?v=0e4bZaP3MDI)
- [TUF Article](https://takeuforward.org/data-structure/count-reverse-pairs/)