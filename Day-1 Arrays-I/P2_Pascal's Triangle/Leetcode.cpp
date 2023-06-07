//* https://leetcode.com/problems/pascals-triangle/description/
//* https://youtu.be/bR7mQgwQ_o8

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //* Brute Force Approach-> O(n^3)
        // Brute_Force obj;
        // return obj.brute(numRows);

        //* Optimal Approach-> O(n^2)
        Optimal op;
        return op.Solution(numRows);
    }

    //* Brute Force Approach-> O(n^3)
    class Brute_Force{
    public:
        vector<vector<int>> brute(int n){
            
            vector<vector<int>> ans;

            for(int row = 1; row <= n; row++){
                vector<int> temp;

                for(int col = 1; col <= row; col++){
                    temp.push_back(nCr(row-1, col-1));
                }

                ans.push_back(temp);
            }

            return ans;
            }

        int nCr(int n, int r){
            int ans = 1;
        
            for(int i = 0; i < r; i++){
                ans = ans * (n-i);
                ans = ans / (i+1);
            }

            return ans;
        }
    };


    //* Optimal Approach->
    class Optimal{
    private:
        vector<int> generateRow(int row){
        
            int ans = 1;
            vector<int> ansRow{ans};

            for(int col = 1; col < row; col++){
                ans = ans * (row-col);
                ans = ans / col;

                ansRow.push_back(ans);
            }

            return ansRow;
        }

    public:
        vector<vector<int>> Solution(int n){
        
            vector<vector<int>> ans;
        
            for(int row = 1; row <= n; row++){
                ans.push_back(generateRow(row));
            }
        
            return ans;
        }
    };    
};