//* https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
//* https://www.youtube.com/watch?v=n7uwj04E0I4

class Solution{
public:
    //Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m) { 
        // code here 
        
        // * Brute force-2 => TC ->O(n+m), SC-> O(n+m)
        // brute(arr1, arr2, n, m);
        
        //* Optimal Approach-1-> O(n+m) + O(nlogn)
        // comparing and sorting
        // better(arr1, arr2, n, m);
        
        //* Optimal Approach-2-> Using gap method of shell sort technique
        // TC-> every time(gap/2) + pointers =>O(log2(n+m)) + O(n+m)
        optimal(arr1, arr2, n, m);
    }
    
    //* Brute Force Approach
    void brute(long long arr1[], long long arr2[], int n, int m){
        
        vector<long long> arr3(n + m);
        int left = 0, right = 0, ind = 0;
        while(left < n && right < m){
            if(arr1[left] <= arr2[right]){
                arr3[ind++] = arr1[left++];
            }
            else{
                arr3[ind++] = arr2[right++];
            }
        }
        while(left < n){
            arr3[ind++] = arr1[left++];
        }
        while(right < m){
            arr3[ind++] = arr2[right++];
        }
        
        //* copying sorted elements back to arr1 and arr2        
        ind = 0;
        while(ind < (n + m)){
            
            if(ind < n){
                arr1[ind] = arr3[ind];
            }
            else{
                arr2[ind-n] = arr3[ind];
            }
            
            ind++;
        }
    }
    
    //* Better Approach
    void better(long long arr1[], long long arr2[], int n, int m){
        
        int ptr1 = n-1, ptr2 = 0;
        
        while(ptr1 >= 0 && ptr2 < m){
            if(arr1[ptr1] > arr2[ptr2]){
                swap(arr1[ptr1], arr2[ptr2]);
                ptr1--, ptr2++;
            }
            else break;
        }
        
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
    
    //* Optimal Approach
    void optimal(long long arr1[], long long arr2[], int n, int m){
        
        int len = n + m;
        
        // gap = ceil(len/2)
        int gap = len/2 + len%2;
        
        while(gap > 0){
            
            int left = 0, right = left + gap;
            while(right < len){
                
                // if left is in arr1 and right is in arr2
                if(left < n && right >= n){
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // if left and right both are in arr2
                else if(left >= n){
                    swapIfGreater(arr2, arr2, left-n, right-n);
                }
                // both are in arr1
                else{
                    swapIfGreater(arr1, arr1, left, right);
                }
                
                left++, right++;
            }
            
            // 2nd time gap is 1
            if(gap == 1){
                break;
            }
            
            // update gap-> gap = ceil(gap/2);
            gap = (gap/2) + (gap%2);
        }
    }
    void swapIfGreater(long long arr1[], long long arr2[], int left, int right){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
        }
    }
};