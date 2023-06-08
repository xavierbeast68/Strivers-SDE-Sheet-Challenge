
<!-- Heading -->
<h1> Merge Sorted Array
 </h1>


<p style="color : rgba(255, 255, 255, 0.65);padding-bottom: 0.25rem; padding-top: 0.25rem;    padding-left: 0.625rem; padding-right: 0.625rem; display:inline; font-size: 1.25rem">Easy</p>

<br>

<!-- Problem Statement -->
You are given two integer arrays <code>nums1</code> and <code>nums2</code>, sorted in **non-decreasing order**, and two integers <code>m</code> and <code>n</code>, representing the number of elements in <code>nums1</code> and <code>nums2</code> respectively.

**Merge** <code>nums1</code> and <code>nums2</code> into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be *stored inside the array* <code>nums1</code>. To accommodate this, <code>nums1</code> has a length of <code>m + n</code>, where the first <code>m</code> elements denote the elements that should be merged, and the last <code>n</code> elements are set to <code>0</code> and should be ignored. <code>nums2</code> has a length of <code>n</code>.

<!-- line break -->
<p>&nbsp</p>

<!-- example 1 -->
<strong>Example 1:</strong>
<pre>
<strong>Input:</strong> nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
<strong>Output:</strong> [1,2,2,3,5,6]
<strong>Explanation:</strong> The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [<u>1</u>,<u>2</u>,2,<u>3</u>,5,6] with the underlined elements coming from nums1.
</pre>

<!-- example 2 -->
<strong>Example 2:</strong>
<pre>
<strong>Input:</strong> nums1 = [1], m = 1, nums2 = [], n = 0
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The arrays we are merging are [1] and [].
The result of the merge is [1].
</pre>

<!-- example 3 -->
<strong>Example 3:</strong>
<pre>
<strong>Input:</strong> nums1 = [0], m = 0, nums2 = [1], n = 1
<strong>Output:</strong> [1]
<strong>Explanation:</strong> The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
</pre>


<!-- line break -->
<p>&nbsp</p>


<!-- constraints -->
<strong>Constraints:</strong>
- <p><code>nums1.length == m + n</code></p>
- <p><code>nums2.length == n</code></p>
- <p><code>0 <= m, n <= 200</code></p>
- <p><code>1 <= m + n <= 200</code></p>
- <p><code>-10<sup>9</sup> <= nums1[i], nums2[j] <= 10<sup>9</sup></code></p>


<!-- line break -->
<p>&nbsp</p>

<!-- Follow up -->
<strong>Follow up:</strong> Can you come up with an algorithm that runs in <code>O(m + n)</code> time?

<!-- line break -->
<p>&nbsp</p>


<!-- horizontal rule -->
<hr>


<!-- Practice Link -->
<h3> Practice Links : </h3>

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/1214628)
- [Leetcode](https://leetcode.com/problems/find-the-duplicate-number/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0)

<hr>

<!-- Resources -->
<h3> Solution Links : </h3>

- [Striver's Video](https://www.youtube.com/watch?v=n7uwj04E0I4)
- [TUF Article](https://takeuforward.org/data-structure/merge-two-sorted-arrays-without-extra-space/)