//* https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //* Brute force
        // nums1.resize(m);
        // nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        // sort(nums1.begin(),nums1.end());

        //* Brute force-2 => TC ->O(n+m), SC-> O(n+m)
        // vector<int> nums3(m + n);
        // int left = 0, right = 0, ind = 0;
        // while(left < m && right < n){
        //     if(nums1[left] <= nums2[right]){
        //         nums3[ind++] = nums1[left++];
        //     }
        //     else{
        //         nums3[ind++] = nums2[right++];
        //     }
        // }
        // while(left < m){
        //     nums3[ind++] = nums1[left++];
        // }
        // while(right < n){
        //     nums3[ind++] = nums2[right++];
        // }
        // nums1 = nums3; // copy nums3 into nums1


        //* Optimized-> SC-> O(1) 
        // https://www.youtube.com/watch?v=P1Ic85RarKY
        int i = m-1, j = n-1, last = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[last] = nums1[i--];
            }
            else{
                nums1[last] = nums2[j--];
            }
            last--;
        }

        // edge case->
        // if i = -1 and j >= 0, fill nums1 with leftovers of nums2
        while(j >= 0){
            nums1[last--] = nums2[j--];
        }
    }
};