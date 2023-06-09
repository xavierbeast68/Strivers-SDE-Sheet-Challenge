//* https://practice.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1
//* https://www.youtube.com/watch?v=ZYpYur0znng

class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here
        
        Find obj;

        //* Extreme Brute Force-> TC = O(n * m)
        // return obj.brute1(matrix, x);

        //* Brute Force-> making use of row sorted property
        // binary search on every row
        // TC-> O(rows*log(cols))
        // return obj.brute2(matrix, x);

        //* optimized-> if row-wise sorted and column-wise sorted
        // staircase search
        //* TC-> O(n + m)
        return obj.optimized(matrix, x);
    }
    
    class Find{
    public:
        // Extreme Brute Force Approach
        bool brute1(vector<vector<int>>& mat, int target){
            int rows = mat.size();
            int cols = mat[0].size();

            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(mat[i][j] == target){
                        return true;
                    }
                }
            }

            return false;
        }

        // Brute Force using Binary Search
        bool brute2(vector<vector<int>>& mat, int target){
            int rows = mat.size();

            for(int i = 0; i < rows; i++){
                if(binary_search(mat[i].begin(), mat[i].end(), target) == true){
                    return true;
                }
            }

            return false;
        }

        //* optimized Approach
        bool optimized(vector<vector<int>>& mat, int target){
            int rows = mat.size();
            int cols = mat[0].size();

            //* starting from upper right corner
            int i = 0,j = cols-1;
            while(i < rows && j >= 0){
                if(target == mat[i][j]){
                    return true;
                }
                else if(target < mat[i][j]){
                    j--;
                }
                else{
                    i++;
                }
            }

            return false;
        }
    };
};