
# Problem Statement :


Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.




#### Example 1:

![App Screenshot](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

#### Example 2:

![App Screenshot](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


#### Constraints:

- m == matrix.length
- n == matrix[0].length
- 1 <= m, n <= 200
- -231 <= matrix[i][j] <= 231 - 1

#### Follow up:

- A straightforward solution using O(mn) space is probably a bad idea.
- A simple improvement uses O(m + n) space, but still not the best solution.
- Could you devise a constant space solution?

---
## Practice Links :

- [CodeStudio](https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website)
- [Leetcode](https://leetcode.com/problems/set-matrix-zeroes/)
- [GeeksforGeeks](https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1)

---
## Solution Links :

- [Striver's Video](https://youtu.be/N0MgLvceX7M)
- [TUF Article](https://takeuforward.org/data-structure/set-matrix-zero/)