//* https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
//* https://youtu.be/AHZpyENo7k4

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        long long maxSum = INT_MIN;
        long long currSum = 0;
        int maxElement = INT_MIN; // in case all elements are -ve, we must choose least -ve.
        
        for (int i = 0; i < n; i++)
        {
            currSum += arr[i];
            
            if(currSum < 0){
                currSum = 0;
            }
            
            maxSum = max(maxSum, currSum);
            
            maxElement = max(maxElement, arr[i]);
        }
        
        return (maxSum == 0 ? maxElement : maxSum);
    }
};