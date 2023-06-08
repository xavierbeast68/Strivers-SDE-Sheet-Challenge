//* https://www.codingninjas.com/codestudio/problems/count-inversions_615
//* https://www.youtube.com/watch?v=AseUmwVNaoY

#include <bits/stdc++.h> 
using namespace std;

class MergeAlgo{
public:
    long long merge(long long arr[], int low, int mid, int high) {
        vector<long long> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

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
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt; //* Modification 3
    }

    long long mergeSort(long long arr[], int low, int high) {
        
        long long cnt = 0;
        
        if (low >= high) return cnt;
        
        int mid = (low + high) / 2 ;
        
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves
        
        return cnt;
    }

    long long numberOfInversions(long long arr[], int n) {

        // Count the number of pairs:
        return mergeSort(arr, 0, n - 1);
    }
};

long long brute(long long arr[], int n){
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


long long getInversions(long long *arr, int n){
    // Write your code here.

    // Brute Force-> TC-> O(n^2), SC->O(1)
    // return brute(arr, n);

    //* Optimal-> TC-> O(nlogn), modifying merge sort algorithm
    MergeAlgo obj;
    return obj.numberOfInversions(arr, n);
}