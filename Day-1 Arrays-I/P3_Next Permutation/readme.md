
<!-- Heading -->
<h1> Next Permutation </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Medium</p>

<br>

<!-- Problem Statement -->
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

- For example, for `arr = [1,2,3]`, the following are all the permutations of `arr`: `[1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1]`.

The <strong>next permutation</strong> of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the <strong>next permutation</strong> of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

- For example, the next permutation of `arr = [1,2,3]` is `[1,3,2]`.
- Similarly, the next permutation of `arr = [2,3,1]` is `[3,1,2]`.
- While the next permutation of `arr = [3,2,1]` is `[1,2,3]` because `[3,2,1]` does not have a lexicographical larger rearrangement.

Given an array of integers `nums`, find the next permutation of `nums`.

The replacement must be in [place](http://en.wikipedia.org/wiki/In-place_algorithm) and use only constant extra memory.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [1,3,2]
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums = [3,2,1]
<strong>Output:</strong> [1,2,3]
</pre>

<!-- example 3 -->
<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums = [1,1,5]
<strong>Output:</strong> [1,5,1]
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`


<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)
- [Leetcode](https://leetcode.com/problems/next-permutation/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/next-permutation5226/1)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://youtu.be/JDOXKqF60RQ)
- [TUF Article](https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/)