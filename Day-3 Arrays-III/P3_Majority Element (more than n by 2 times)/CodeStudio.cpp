//* https://www.codingninjas.com/codestudio/problems/majority-element_842495
//* https://www.youtube.com/watch?v=nP_ns3uSh80

#include <bits/stdc++.h> 
using namespace std;

class Majority{
public:
	int brute(int arr[], int n){
		
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(arr[i] == arr[j]){
					cnt++;
				}
			}

			if(cnt > n/2){
				return arr[i];
			}
		}
		
		return -1;
	}

	// Using Hashing
	int better(int arr[], int n){
		
		unordered_map<int,int> mp;
		for(int i = 0; i < n; i++){
			mp[arr[i]]++;

			if(mp[arr[i]] > n/2){
				return arr[i];
			}
		}

		return -1;
	}

	// Using Moore's Voting Algorithm
	int optimal(int arr[], int n){
		int cnt = 0;
		int el;
		for(int i = 0; i < n; i++){
			if(cnt == 0){
				el = arr[i];
				cnt++;
			}
			else if(arr[i] == el){
				cnt++;
			}
			else{
				cnt--;
			}
		}

		int cnt1 = 0;
		// check
		for(int i = 0; i < n; i++){
			if(arr[i] == el){
				cnt1++;
			}

			if(cnt1 > n/2){
				return arr[i];
			}
		}

		return -1;
	}
};

int findMajorityElement(int arr[], int n) {
	// Write your code here.

	Majority obj;

	//* Brute Force->
	// TC- O(N^2)
	// return obj.brute(arr, n);

	//* Better-> using Hashing
	// TC-> O(n), SC-> O(n)
	// return obj.better(arr, n);

	//* Optimal-> Using Moore's Voting Algorithm
	// TC- O(n), SC- O(n)
	return obj.optimal(arr, n);
}