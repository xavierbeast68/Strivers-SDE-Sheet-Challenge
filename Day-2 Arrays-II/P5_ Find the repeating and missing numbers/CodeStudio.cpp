//* https://www.codingninjas.com/codestudio/problems/873366
//* https://www.youtube.com/watch?v=2D0D8HE6uak

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	pair<int,int> brute1(vector<int>& arr, int n){
		
		pair<int, int> ans;

		for(int i = 1; i <= n; i++){

			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(i == arr[j]){
					cnt++;
				}
			}

			if(cnt == 0){
				ans.first = i;
			}
			if(cnt > 1){
				ans.second = i;
			}
		}

		return ans;
	}

	pair<int,int> brute2(vector<int>& arr, int n){
		
		pair<int, int> ans;
		unordered_map<int,int> freq;

		for(int i = 0; i < n; i++){
			freq[arr[i]]++;
		}

		for(int num = 1; num <= n; num++){
			if(freq[num] == 0) ans.first = num;
			if(freq[num] > 1) ans.second = num;
		}

		return ans;
	}

	pair<int,int> optimal_Math(vector<int>& arr){
		//* use long long to avoid overflows
		// x-> repeating, y-> missing

		long long n = arr.size(); // size of the array

    	// Find Sn and S2n:
    	long long SN = (n * (n + 1)) / 2;
    	long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    	// Calculate S and S2:
    	long long S = 0, S2 = 0;
    	for (int i = 0; i < n; i++) {
    	    S += arr[i];
    	    S2 += (long long)arr[i] * (long long)arr[i];
    	}

		// Equation-1
		//S-Sn = X-Y:
		long long val1 = S - SN;

		// Equation-2
		// S2-S2n = X^2-Y^2:
		long long val2 = S2 - S2N;

		//Find X+Y = (X^2-Y^2)/(X-Y):
		val2 = val2 / val1;

		//Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
		// Here, X-Y = val1 and X+Y = val2:
		long long x = (val1 + val2) / 2;
		long long y = x - val1;

		return {(int)y, (int)x};
	}

	pair<int, int> optimal_XOR(vector<int>& a){
		int n = a.size(); // size of the array

		int xr = 0;
		//Step 1: Find XOR of all elements:
		for (int i = 0; i < n; i++) {
			xr = xr ^ a[i];
			xr = xr ^ (i + 1);
		}

		//Step 2: Find the differentiating bit number:
		int number = (xr & ~(xr - 1));
		/* Loop Method to find bit number->
		
		number = 0;
		while(1){
			if(xr && (1 << number)){
				break;
			}
			number++;
		}
		*/

		//Step 3: Group the numbers:
		int zero = 0;
		int one = 0;
		for (int i = 0; i < n; i++) {
			//part of 1 group:
			if ((a[i] & number) != 0) {
				one = one ^ a[i];
			}
			//part of 0 group:
			else {
				zero = zero ^ a[i];
			}
		}
		for (int i = 1; i <= n; i++) {
			//part of 1 group:
			if ((i & number) != 0) {
				one = one ^ i;
			}
			//part of 0 group:
			else {
				zero = zero ^ i;
			}
		}

		// Last step: Identify the numbers:
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == zero) cnt++;
		}
		if (cnt == 2) return {one, zero};
		return {zero, one};
	}
};

pair<int,int> missingAndRepeating(vector<int> &arr, int n){
	// Write your code here 
	
	Solution obj;

	//* Exterme Brute Force-> O(n^2)
	// return obj.brute1(arr, n);

	//* Brute Force-> TC-> O(n), SC-> O(n), using maps
	// return obj.brute2(arr, n);

	//* Optimal-> Using Maths-> TC->O(n), SC->O(1)
	// return obj.optimal_Math(arr);

	//* Optimal-> Using XOR-> TC->O(n), SC->O(1)
	return obj.optimal_XOR(arr);
}
