//* https://www.codingninjas.com/codestudio/problems/1112602
//* https://www.youtube.com/watch?v=32Ll35mhWg0

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brute(vector<int>& nums, int n){
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

    int better(vector<int>& nums, int n){
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

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.

	Solution obj;

	// Brute Force-> TC ≅ O(n^2), SC-> O(1)
    // return obj.brute(arr, n);

    //* Better Approach-> Using Maps or frequency count
    // TC-> O(n), SC-> O(n)
    // return obj.better(arr, n);

    //* Optimal Approach-> Linked List Cycle Method
    // TC-> O(n),  SC-> O(1)
    return obj.optimal(arr);
}
