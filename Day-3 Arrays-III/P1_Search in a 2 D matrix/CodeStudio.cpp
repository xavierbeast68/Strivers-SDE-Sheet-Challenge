//* https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531
//* https://www.youtube.com/watch?v=ZYpYur0znng

#include<bits/stdc++.h>
using namespace std;

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

    //* Better Approach
    bool better(vector<vector<int>>& mat, int target){
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
    //* Optimzed Approach
    bool optimized(vector<vector<int>>& mat, int target){
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0, high = (rows * cols - 1);

        while(low <= high){
            int mid = low + (high - low)/2;

            if(mat[mid / cols][mid % cols] == target){
                return true;
            }
            else if(mat[mid / cols][mid % cols] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return false;
    }
};


bool searchMatrix(vector<vector<int>>& mat, int target) {
    Find obj;

    //* Extreme Brute Force-> TC = O(n * m)
    // return obj.brute1(mat, target);

    //* Brute Force-> making use of row sorted property
    // binary search on every row
    // TC-> O(rows*log(cols))
    // return obj.brute2(mat, target);

    //* Better-> if row-wise sorted and column-wise sorted
    // staircase search
    //* TC-> O(n + m)
    // return obj.better(mat, target);

    //* Optimized Approach-> if mat is combined row-wise, becomes a sorted array, perform binary search on that
    // TC = O(log(n*m)), SC= O(1)
    return obj.optimized(mat, target);
}