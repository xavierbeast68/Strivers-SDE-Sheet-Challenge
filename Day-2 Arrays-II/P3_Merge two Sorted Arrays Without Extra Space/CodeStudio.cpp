//* https://www.codingninjas.com/codestudio/problems/1214628


#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.

	//* Brute force
    // arr1.resize(m);
    // arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    // sort(arr1.begin(),arr1.end());

    //* Brute force-2 => TC ->O(n+m), SC-> O(n+m)
    // vector<int> arr3(m + n);
    // int left = 0, right = 0, ind = 0;
    // while(left < m && right < n){
    //     if(arr1[left] <= arr2[right]){
    //         arr3[ind++] = arr1[left++];
    //     }
    //     else{
    //         arr3[ind++] = arr2[right++];
    //     }
    // }
    // while(left < m){
    //     arr3[ind++] = arr1[left++];
    // }
    // while(right < n){
    //     arr3[ind++] = arr2[right++];
    // }
    // return arr3;


    //* Optimized-> SC-> O(1) 
    // https://www.youtube.com/watch?v=P1Ic85RarKY
    int i = m-1, j = n-1, last = m + n - 1;

    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[last] = arr1[i--];
        }
        else{
            arr1[last] = arr2[j--];
        }
        last--;
    }

    // edge case->
    // if i = -1 and j >= 0, fill arr1 with leftovers of arr2
    while(j >= 0){
        arr1[last--] = arr2[j--];
    }

    return arr1;
}