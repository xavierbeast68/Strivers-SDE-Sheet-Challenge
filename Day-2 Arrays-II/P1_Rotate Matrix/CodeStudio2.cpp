//* https://www.codingninjas.com/codestudio/problems/rotate-matrix-by-90-degrees_981261
//* https://www.youtube.com/watch?v=Z0R2u6gd3GU
//* https://www.codingninjas.com/codestudio/problem-details/inplace-rotate-matrix-90-degree_839734


#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    void brute_force(vector<vector<int>>& matrix){
        /*
            observation->
            every a[i][j] -> a[n-1-j][i]
        */

        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[n-1-j][i] = matrix[i][j];
            }
        }

        matrix = ans;
    }

    void better(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int startRow = 0, endRow = n-1;
        int startCol = 0, endCol = n-1;

        for(int level = 1; level <= n/2 ; level++){

            int counter = 0;
            while(counter < (endRow - startRow)){
                int temp = matrix[startRow][startCol + counter];
                
                matrix[startRow][startCol + counter] = matrix[startRow + counter][endCol];
                matrix[startRow + counter][endCol] = matrix[endRow][endCol - counter];
                matrix[endRow][endCol - counter] = matrix[endRow - counter][startCol];
                matrix[endRow - counter][startCol] = temp;

                counter++;
            }
            
            startRow++, endRow--;
            startCol++, endCol--;
        }
    }

    void optimal(vector<vector<int>>& matrix){
        int n = matrix.size();

        // reversing each row of the matrix
        // O(n*(n/2))
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // transposing the matrix
        // O(n/2 * n/2)
        for(int i = 0; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};



vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    // Write your code here.

    Solution obj;

    //* Brute Force-> TC-> O(n^2), SC-> O(n*2)
    // obj.brute_force(matrix);
    // return matrix;

    //* Better-> using Spiral Traversal-> TC-> O(n^2)=> O(m) where m = number of cells ,SC-> O(1)
    // obj.better(matrix);
    // return matrix;

    //* Optimal Approach-> reversing each row of the matrix and transpose of the matrix
    // TC-> O(n^2)=> O(m) ,SC-> O(1)
    obj.optimal(matrix);
    return matrix;
    
}