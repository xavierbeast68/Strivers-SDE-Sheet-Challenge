//* https://leetcode.com/problems/find-the-duplicate-number/
//* https://www.youtube.com/watch?v=32Ll35mhWg0

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Brute Force-> TC ≅ O(n^2), SC-> O(1)
        // return brute(nums);

        //* Better Approach-> Using Maps or frequency count
        // TC-> O(n), SC-> O(n)
        // return better(nums);

        //* Optimal Approach-> Linked List Cycle Method
        // TC-> O(n),  SC-> O(1)
        return optimal(nums);
    }

    int brute(vector<int>& nums){
        int n = nums.size();
        int answer;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(nums[i] == nums[j]){
                    answer = nums[i];
                }
            }
        }
        return answer;
    }

    int better(vector<int>& nums){
        int n = nums.size();
        int answer;
        
        map<int,int> mp;
        for(int i : nums) ++mp[i];
        for(auto i : mp){
            if(i.second > 1){
                answer =  i.first;
            }
        }
        return answer;
    }

    int optimal(vector<int>& nums){

        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};