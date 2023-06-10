//* https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027
//* https://www.youtube.com/watch?v=vwZj1K0e9U8

#include <bits/stdc++.h>
using namespace std;

class Majority{
public:
	vector<int> brute(vector<int>& arr, int n){
		vector<int> ls;

        // minimum number of occurences an 
        // element requires to become majority element
        int mm = floor(n/3) + 1; 

		for(int i = 0; i < n; i++){
			
            if(ls.size() == 0 || ls[0] != arr[i]){
    			int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(arr[i] == arr[j]){;
                        cnt++;
                    }

                    // the moment cnt of arr[i] crosses mm, it becomes majority element
                    if(cnt >= mm){
                        ls.push_back(arr[i]);
                        break;
                    }
                }

            }

            // at max 2 majority elements can exists in an array 
            // if both appear atleast mm times
            if(ls.size() == 2){
                break;
            }
		}
		
		return ls;
	}

	// Using Hashing
	vector<int> better(vector<int>& arr, int n){
		vector<int> ls;
        int mm = floor(n/3) + 1; // maximum majority elements that can exists

		unordered_map<int,int> mp;
		for(int i = 0; i < n; i++){
			mp[arr[i]]++;

			if(mp[arr[i]] == mm){
				ls.push_back(arr[i]);
			}

            if(ls.size() == 2){
                break;
            }
		}

		return ls;
	}

	// Using Extended Boyer Moore’s Voting Algorithm
	vector<int> optimal(vector<int>& arr, int n){
        vector<int> ls;
        int mm = floor(n/3) + 1; // maximum majority elements that can exists

		int cnt1 = 0, cnt2 = 0;
		int el1 = INT_MIN, el2 = INT_MIN; // 1st and 2nd majority elements
		for(int i = 0; i < n; i++){
			if(cnt1 == 0 && arr[i] != el2){
                cnt1 = 1;
                el1 = arr[i];
            }
            else if(cnt2 == 0 && arr[i] != el1){
                cnt2 = 1;
                el2 = arr[i];
            }
            else if(arr[i] == el1) cnt1++;
            else if(arr[i] == el2) cnt2++;
            else{
                cnt1--, cnt2--;
            }
		}

		cnt1 = 0, cnt2 = 0;
		// check
		for(int i = 0; i < n; i++){
			if(arr[i] == el1){
				cnt1++;
			}

			if(arr[i] == el2){
				cnt2++;
			}
		}

        if(cnt1 >= mm){
            ls.push_back(el1);
        }
        if(cnt2 >= mm){
            ls.push_back(el2);
        }
        sort(ls.begin(), ls.end()); // 2*log2 equals constant TC 
		return ls;
	}
};


vector<int> majorityElementII(vector<int> &v)
{
    // Write your code here.

    int n = v.size();
    Majority obj;

	//* Brute Force->
	// TC- O(n^2)
	// return obj.brute(v, n);

	//* Better-> using Hashing
	// TC-> O(n), SC-> O(n)
	// return obj.better(v, n);

	//* Optimal-> Using Extended Boyer Moore’s Voting Algorithm
	// TC- O(n), SC- O(n)
	return obj.optimal(v, n);
}