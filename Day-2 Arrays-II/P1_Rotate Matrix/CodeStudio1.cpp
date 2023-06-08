//* https://www.codingninjas.com/codestudio/problems/981260
//* https://www.youtube.com/watch?v=Z0R2u6gd3GU
//* https://www.codingninjas.com/codestudio/problem-details/rotate-matrix_981260


#include <bits/stdc++.h>
using namespace std;


void iter(vector<vector<int>> &mat, int startRow, int startCol, 
            int endRow, int endCol){
    
    while(startRow < endRow && startCol < endCol){

        int temp1 = mat[startRow][endCol];
        for(int j = endCol; j > startCol; j--){
            mat[startRow][j] = mat[startRow][j-1];
        }

        int temp2 = mat[endRow][endCol];
        for(int i = endRow; i > startRow; i--){
            mat[i][endCol] = mat[i-1][endCol];
        }
        mat[startRow+1][endCol] = temp1;

        int temp3 = mat[endRow][startCol];
        for(int j = startCol; j < endCol; j++){
            mat[endRow][j] = mat[endRow][j+1];
        }
        mat[endRow][endCol-1] = temp2;

        for(int i = startRow; i < endRow; i++){
            mat[i][startCol] = mat[i+1][startCol];
        }
        mat[endRow-1][startCol] = temp3;



        startRow++, startCol++;
        endRow--, endCol--;
    }
}

void rec(vector<vector<int>> &mat, int startRow, int startCol, 
            int endRow, int endCol){
    
    if(endRow <= startRow || endCol <= startCol){
        return;
    }

    int temp1 = mat[startRow][endCol];
    for(int j = endCol; j > startCol; j--){
        mat[startRow][j] = mat[startRow][j-1];
    }

    int temp2 = mat[endRow][endCol];
    for(int i = endRow; i > startRow; i--){
        mat[i][endCol] = mat[i-1][endCol];
    }
    mat[startRow+1][endCol] = temp1;

    int temp3 = mat[endRow][startCol];
    for(int j = startCol; j < endCol; j++){
        mat[endRow][j] = mat[endRow][j+1];
    }
    mat[endRow][endCol-1] = temp2;

    for(int i = startRow; i < endRow; i++){
        mat[i][startCol] = mat[i+1][startCol];
    }
    mat[endRow-1][startCol] = temp3;



    startRow++, startCol++;
    endRow--, endCol--;

    rec(mat, startRow, startCol, endRow, endCol);
}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    
    //* Recursive Approach->
    // rec(mat, 0, 0, n-1, m-1);


    //* Iterative Approach->
    iter(mat, 0, 0, n-1, m-1);
}