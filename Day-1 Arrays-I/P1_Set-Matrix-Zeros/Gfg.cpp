//* https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1
//* https://youtu.be/N0MgLvceX7M

class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix){
        // code here 
        
        //* Brute Force Approach-> TLE=> TC->O(n*m*(n+m)), SC->O(1)
        // Brute_Force obj;
        // obj.brute_approach(matrix);

        
        //* Time Optimize Approach-> TC->O(n*m), SC-> O(n)+O(m)
        // time_optimized(matrix);


        //* Space Optimized Aprroach-> TC->O(n*m), SC-> O(1)
        space_optimized(matrix);
    }
    
    
    class Brute_Force{
    private:
        void markRow(int i, vector<vector<int>>& mat, int col){
            for(int j = 0; j < col; ++j){
                if(mat[i][j] != 1){
                    mat[i][j] = -1;
                }
            }
        }
        void markCol(int j, vector<vector<int>>& mat, int row){
            for(int i = 0; i < row; ++i){
                if(mat[i][j] != 1){
                    mat[i][j] = -1;
                }
            }
        }

    public:
        void brute_approach(vector<vector<int>>& mat){
            int n = mat.size();
            int m = mat[0].size();

            // first iteration to mark rows and columns containing 1 with -1
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(mat[i][j] == 1){
                        // make all zero elements of row i to -1
                        markRow(i, mat, m);
                        // make all zero elements of column j to -1
                        markCol(j, mat, n);
                    }
                }
            }

            // convert all -1's to 1
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < m; ++j){
                    if(mat[i][j] == -1){
                        mat[i][j] = 1;
                    }
                }
            }
        }
    };


    void time_optimized(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        
        // using dummy arrays to mark rows & cols containing 1's
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // marking
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 1){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // converting all elements that have either row[i] = 1 or col[j] = 1
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(row[i] == 1 || col[j] == 1){
                    mat[i][j] = 0;
                }
            }
        }
    }


    void space_optimized(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        
        // using 0th row and column of matrix itself to mark rows & cols containing 1's
        // vector<int> row(n, 0);-> mat[...][0]
        // vector<int> col(m, 0);-> mat[0][...]
        int col0 = 0;

        // marking
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 1){
                    // marking row->
                    mat[i][0] = 1;

                    // marking column
                    if(j != 0){
                        mat[0][j] = 1;
                    }
                    else{
                        col0 = 1;
                    }
                }
            }
        }

        // Converting rows from 1->n and columns from 1->m only
        // not manipulating 0th row and 0th column
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                if(mat[0][j] == 1 || mat[i][0] == 1){
                    mat[i][j] = 1;
                }
            }
        }

        // checking for 0th row
        if(mat[0][0] == 1){
            for(int j = 0; j < m; ++j){
                mat[0][j] = 1;
            }
        }
        // checking for 0th column
        if(col0 == 1){
            for(int i = 0; i < n; ++i){
                mat[i][0] = 1;
            }
        }
    }
};