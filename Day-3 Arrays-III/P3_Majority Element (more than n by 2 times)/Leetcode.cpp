//* https://leetcode.com/problems/majority-element/
//* https://www.youtube.com/watch?v=nP_ns3uSh80

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        Majority obj;

	    //* Brute Force->
	    // TC- O(N^2)
	    // return obj.brute(nums, n);

	    //* Better-> using Hashing
	    // TC-> O(n), SC-> O(n)
	    // return obj.better(nums, n);

	    //* Optimal-> Using Moore's Voting Algorithm
	    // TC- O(n), SC- O(n)
	    return obj.optimal(nums, n);
    }

    class Majority{
    public:
        int brute(vector<int>& nums, int n){
            
            for(int i = 0; i < n; i++){
                int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(nums[i] == nums[j]){
                        cnt++;
                    }
                }

                if(cnt > n/2){
                    return nums[i];
                }
            }
            
            return -1;
        }

        // Using Hashing
        int better(vector<int>& nums, int n){
            
            unordered_map<int,int> mp;
            for(int i = 0; i < n; i++){
                mp[nums[i]]++;

                if(mp[nums[i]] > n/2){
                    return nums[i];
                }
            }

            return -1;
        }

        // Using Moore's Voting Algorithm
        int optimal(vector<int>& nums, int n){
            int cnt = 0;
            int el;
            for(int i = 0; i < n; i++){
                if(cnt == 0){
                    el = nums[i];
                    cnt++;
                }
                else if(nums[i] == el){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }

            int cnt1 = 0;
            // check
            for(int i = 0; i < n; i++){
                if(nums[i] == el){
                    cnt1++;
                }

                if(cnt1 > n/2){
                    return nums[i];
                }
            }

            return -1;
        }
    };
};