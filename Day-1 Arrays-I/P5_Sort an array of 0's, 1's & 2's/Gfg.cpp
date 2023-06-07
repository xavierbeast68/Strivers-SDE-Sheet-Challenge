//* https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
//* https://youtu.be/tp8JIuCXBaU

class Solution
{
    public:
    void sort012(int a[], int n){
        // code here 
        
        //* Brute Force-> Apply Sorting Algorithm => O(nlogn)
        // sort(a, a + n);
        
        //* Better Approach-> O(n)
        // better(a, n);
        
        //* Optimal Approach-> O(n)
        //* Dutch National Flag Algorithm
        dnf_algo(a, n);
    }
    
    void better(int arr[], int n){

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) cnt0++;
            else if(arr[i] == 1) cnt1++;
            else cnt2++;
        }

        for(int i = 0; i < cnt0; i++) arr[i] = 0;
        for(int i = cnt0; i < cnt0+cnt1; i++) arr[i] = 1;
        for(int i = cnt0+cnt1; i < n; i++) arr[i] = 2;
    }

    /// Optimal Approach-> Dutch National Flag Algorithm
    void dnf_algo(int arr[], int n){
        int low = 0, mid = 0,  high = n-1;

        while(mid <= high){

            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                low++, mid++;
            }

            else if(arr[mid] == 1){
                mid++;
            }
            // arr[mid] == 2
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};