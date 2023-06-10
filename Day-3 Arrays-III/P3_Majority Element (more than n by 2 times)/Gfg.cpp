//* https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1
//* https://www.youtube.com/watch?v=nP_ns3uSh80

class Solution{
public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size){
        
        // your code here
        
        Majority obj;

    	//* Brute Force->
    	// TC- O(size^2)
    	// return obj.brute(a, size);
    
    	//* Better-> using Hashing
    	// TC-> O(size), SC-> O(size)
    	// return obj.better(a, size);
    
    	//* Optimal-> Using Moore's Voting Algorithm
    	// TC- O(size), SC- O(size)
    	return obj.optimal(a, size);
    }
    class Majority{
    public:
        int brute(int nums[], int n){
            
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
        int better(int nums[], int n){
            
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
        int optimal(int nums[], int n){
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