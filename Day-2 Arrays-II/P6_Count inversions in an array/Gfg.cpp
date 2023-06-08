//* https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
//* https://www.youtube.com/watch?v=AseUmwVNaoY

class Solution{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N){
        // Your Code Here
        
        // Brute Force-> TC-> O(n^2), SC->O(1)
        // return brute(arr, N);
    
        //* Optimal-> TC-> O(nlogn), modifying merge sort algorithm
        MergeAlgo obj;
        return obj.numberOfInversions(arr, N);
    }
    
    class MergeAlgo{
    public:
        long long merge(long long arr[], long long low, long long mid, long long high) {
            vector<long long> temp; // temporary array
            long long left = low;      // starting index of left half of arr
            long long right = mid + 1;   // starting index of right half of arr
    
            //* Modification 1: cnt variable to count the pairs:
            long long cnt = 0;
    
            //storing elements in the temporary array in a sorted manner//
    
            while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                }
                else {
                    temp.push_back(arr[right]);
                    cnt += 1LL*(mid - left + 1); //* Modification 2
                    right++;
                }
            }
    
            // if elements on the left half are still left //
    
            while (left <= mid) {
                temp.push_back(arr[left]);
                left++;
            }
    
            //  if elements on the right half are still left //
            while (right <= high) {
                temp.push_back(arr[right]);
                right++;
            }
    
            // transfering all elements from temporary to arr //
            for (long long i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
    
            return cnt; //* Modification 3
        }
    
        long long mergeSort(long long arr[], long long low, long long high) {
            
            long long cnt = 0;
            
            if (low >= high) return cnt;
            
            long long mid = (low + high) / 2 ;
            
            cnt += mergeSort(arr, low, mid);  // left half
            cnt += mergeSort(arr, mid + 1, high); // right half
            cnt += merge(arr, low, mid, high);  // merging sorted halves
            
            return cnt;
        }
    
        long long numberOfInversions(long long arr[], long long n) {
    
            // Count the number of pairs:
            return mergeSort(arr, 0, n - 1);
        }
    };
    
    long long brute(long long arr[], long long n){
        long long cnt = 0;
    
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(arr[i] > arr[j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }    
};