//* https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146
//* https://www.youtube.com/watch?v=l0YC3876qxg
//* https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

#include <bits/stdc++.h>
using namespace std;

int modExpo(long long x, long long n, int mod){
    int ans = 1;

    x = x % mod;

    while(n > 0){
        // odd power
        if(n % 2 == 1){
            ans = (ans * x) % mod;
            n = n - 1;
        }
        // // even power
        // else{
        //     x = x * x;
        //     n = n / 2;
        // }

        /*
            if n becomes odd, then after n = n-1, n becomes even automatically,
            and thus we save one extra iteration in iterations starting with odd n
        */
        x = (x * x) % mod; 
        n = n / 2;
    }
    return ans;
}

int modularExponentiation(int x, int n, int m) {
	// Write your code here.

	return modExpo(x, n, m);
}