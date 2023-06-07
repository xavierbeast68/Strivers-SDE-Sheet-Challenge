//* https://www.codingninjas.com/codestudio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
//* https://youtu.be/bR7mQgwQ_o8

#include <bits/stdc++.h>
using namespace std;

//* Brute Force Approach-> O(n^3)
class Brute_Force{
public:
    vector<vector<long long int>> brute(int n){
        
        vector<vector<long long int>> ans;

        for(int row = 1; row <= n; row++){
            vector<long long int> temp;

            for(int col = 1; col <= row; col++){
                temp.push_back(nCr(row-1, col-1));
            }

            ans.push_back(temp);
        }

        return ans;
    }

    long long nCr(int n, int r){
        long long ans = 1;
    
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
    vector<long long int> generateRow(int row){
    
        long long ans = 1;
        vector<long long int> ansRow{ans};

        for(int col = 1; col < row; col++){
            ans = ans * (row-col);
            ans = ans / col;

            ansRow.push_back(ans);
        }

        return ansRow;
    }

public:
    vector<vector<long long int>> Solution(int n){
    
        vector<vector<long long int>> ans;

        for(int row = 1; row <= n; row++){
            ans.push_back(generateRow(row));
        }

        return ans;
    }
};

vector<vector<long long int>> printPascal(int n) {

    // Write your code here.

    //* Brute Force Approach-> O(n^3)
    // Brute_Force obj;
    // return obj.brute(n);

    //* Optimal Approach-> O(n^2)
    Optimal op;
    return op.Solution(n);
}
