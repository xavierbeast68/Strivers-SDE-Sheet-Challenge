//* https://leetcode.com/problems/rotate-image/
//* https://www.youtube.com/watch?v=Z0R2u6gd3GU


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //* Brute Force-> TC-> O(n^2), SC-> O(n*2)
        // brute_force(matrix);

        //* Optimal-> Spiral Traversal-> TC-> O(n^2)=> O(m) ,SC-> O(1)
        // optimal1(matrix);

        //* Optimal2-> using transpose of the matrix and then reversing each row of it
        // TC-> O(n^2)=> O(m) ,SC-> O(1)
        optimal2(matrix);
    }

    void brute_force(vector<vector<int>>& matrix){
        /*
            observation->
            every a[i][j] -> a[j][n-1-i]
        */

        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n-1-i] = matrix[i][j];
            }
        }

        matrix = ans;
    }

    // using spiral traversal  
    void optimal1(vector<vector<int>>& matrix){
        int n = matrix.size();
        int startRow = 0, endRow = n-1;
        int startCol = 0, endCol = n-1;

        for(int level = 1; level <= n/2 ; level++){

            int counter = 0;
            while(counter < (endRow - startRow)){
                int temp = matrix[startRow][startCol + counter];
                matrix[startRow][startCol + counter] = matrix[endRow - counter][startCol];
                matrix[endRow - counter][startCol] = matrix[endRow][endCol - counter];
                matrix[endRow][endCol - counter] = matrix[startRow + counter][endCol];
                matrix[startRow + counter][endCol] = temp;

                counter++;
            }

            startRow++, endRow--;
            startCol++, endCol--;
        }
    }

    void optimal2(vector<vector<int>>& matrix){
        int n = matrix.size();

        // transposing the matrix
        for(int i = 0; i <= n - 2; i++){
            for(int j = i + 1; j <= n - 1; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reversing each row of the matrix
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};