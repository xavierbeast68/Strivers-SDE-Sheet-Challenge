//* https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470
//* https://www.youtube.com/watch?v=t_f0nwwdg5o
//* https://youtu.be/sdE0A2Oxofw

#include <bits/stdc++.h> 
using namespace std;

//* Recursion
int rec(int row, int col){
	if(row == 0 && col == 0){
		return 1;
	}
	if(row < 0 || col < 0){
		return 0;
	}

	int up = rec(row-1,col);
	int left = rec(row,col-1);
	return up + left;
}

//* DP Memoization
int memo(int row, int col, vector<vector<int>>& dp){
	if(row == 0 && col == 0){
		return 1;
	}
	if(row < 0 || col < 0){
		return 0;
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int up = memo(row-1,col, dp);
	int left = memo(row,col-1, dp);
	return dp[row][col] = up+left;
}

//* DP Tabulation
int tab(int m, int n){

	int dp[m][n]; // dp[0][0] = 1
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			if(i == 0 && j == 0){
				dp[i][j] = 1;
			}
			else{
				int up = 0, left = 0;
				if(i > 0){
					up = dp[i-1][j];
				}
				if(j > 0){
					left = dp[i][j-1];
				}

				dp[i][j] = up + left;
			}
		}
	}
	return dp[m-1][n-1];
}

//* DP Tabulation + Space Optimization
int so(int m, int n){
	vector<int> prev(n, 0);
	for(int i = 0; i < m; ++i){
		vector<int> curr(n, 0);
		for(int j = 0; j < n; ++j){
			if(i == 0 && j == 0){
				curr[j] = 1;
			}
			else{
				int up = 0, left = 0;
				if(i > 0){
					up = prev[j];
				}
				if(j > 0){
					left = curr[j-1];
				}

				curr[j] = up + left;
			}
		}
		prev = curr;
	}
	return prev[n-1];
}

//* Using Combinatorics
int comb(int m, int n){
	int N = m + n -2;
	int r = min(m-1, n-1);
	double ans = 1;

	for(int i = 0; i < r; i++){
		ans = ans * (N - i) / (i + 1);
	}

	return (int)ans;
}
int uniquePaths(int m, int n) {
	// Write your code here.

	//* Recrusive Soln-> TLE, 
	// TC->O(2^(m*n)) Exponential(explore all paths), SC-> Recursive stack space
	// return rec(m-1,n-1);

	//* DP Memoization->
	// TC-> O(m*n), SC-> O(n-1)+O(m-1)+O(m*n)
	// vector<vector<int>> dp(m, vector<int>(n,-1));
	// return memo(m-1,n-1,dp);

	//* DP Tabulation->
	// TC-> O(m*n), SC-> O(m*n)
	// return tab(m, n);

	//* DP (Tabulation + Space Optimisation)
	// TC-> O(m*n), SC-> O(n)
	// return so(m, n);

	//* Using Combinatorics
	// TC-> O(m-1) or O(n-1), SC-> O(1)
	return comb(m, n);
}