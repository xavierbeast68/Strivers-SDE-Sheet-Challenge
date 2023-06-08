//* https://leetcode.com/problems/next-permutation/
//* https://youtu.be/JDOXKqF60RQ


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // using next_permutation() function
        // next_permutation(begin(nums), end(nums));


        int N = nums.size();

        if (N == 1){
            return;
        }

        // find index i such that arr[i] < arr[i+1]
        int ind = -1;
        for(int i = N-2; i >= 0; --i){
            if (nums[i] < nums[i + 1]){
                ind = i;
                break;
            }
        }

        // if no such index found, means to reverse the whole permutation
        if (ind == -1){
            reverse(begin(nums), end(nums));
            return;
        }

        // find index of i from back such that arr[i] is just > arr[ind]
        for(int i = N-1; i >= 0; --i)
        {
            if (nums[i] > nums[ind]){
                // swapping->
                swap(nums[i], nums[ind]);
                break;
            }
        }


        // reverse from ind+1 till end
        reverse(nums.begin() + (ind + 1), nums.end());
    }
};