//* https://leetcode.com/problems/reverse-pairs/
//* https://www.youtube.com/watch?v=0e4bZaP3MDI

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        //* Brute Force-> 
        // TC- O(n^2) gives TLE, SC- O(1)
        // return brute(nums);

        //* Optimal Approach-> Using Merge Sort Algorithm
        //* TC- O(2n*logn), SC- O(n);
        MergeAlgo obj;
        return obj.numberOfReversePairs(nums);
    }

    //* Brute Force Approach
    int brute(vector<int>& nums){
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // multiplied with 2LL rather than only 2 in order to avoid integer overflows
                if(nums[i] > 2LL * nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    class MergeAlgo{
    public:
        void merge(vector<int>& arr, int low, int mid, int high) {
            vector<int> temp; // temporary array
            int left = low;      // starting index of left half of arr
            int right = mid + 1;   // starting index of right half of arr
    
            //storing elements in the temporary array in a sorted manner//
    
            while (left <= mid && right <= high) {
                if (arr[left] <= arr[right]) {
                    temp.push_back(arr[left]);
                    left++;
                }
                else {
                    temp.push_back(arr[right]);
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
            for (int i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
        }

        int countPairs(vector<int>& arr, int low, int mid, int high){
            int cnt = 0;
            int right = mid + 1;

            for(int left = low; left <= mid; left++){
                // 2LL in place of 2 in order to avoid integer overflows
                while(right <= high && arr[left] > 2LL * arr[right]){
                    right++;
                }

                cnt += (right - (mid+1));
            }

            return cnt;
        }

        int mergeSort(vector<int>& arr, int low, int high) {
            
            int cnt = 0;
            
            if (low >= high) return cnt;
            
            int mid = (low + high) / 2 ;
            
            cnt += mergeSort(arr, low, mid);  // left half
            cnt += mergeSort(arr, mid + 1, high); // right half
            cnt += countPairs(arr, low, mid, high);
            merge(arr, low, mid, high);  // merging sorted halves
            
            return cnt;
        }
    
        int numberOfReversePairs(vector<int>& arr) {
    
            // Count the number of pairs:
            return mergeSort(arr, 0, arr.size() - 1);
        }
    };
};