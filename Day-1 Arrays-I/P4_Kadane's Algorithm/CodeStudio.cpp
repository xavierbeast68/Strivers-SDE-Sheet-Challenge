//* https://www.codingninjas.com/codestudio/problems/630526?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//* https://youtu.be/AHZpyENo7k4

#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int n){
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */


    long long maxSum = INT_MIN;
    long long currSum = 0;
    
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if(currSum < 0){
            currSum = 0;
        }
        
        maxSum = max(maxSum, currSum);
    }
    return maxSum == 0 ? 0 : maxSum;
}