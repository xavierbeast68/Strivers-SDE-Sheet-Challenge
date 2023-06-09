//* https://www.codingninjas.com/codestudio/problems/find-power-of-a-number_893198
//* https://www.youtube.com/watch?v=l0YC3876qxg
//* https://leetcode.com/problems/powx-n/editorial/


#include <bits/stdc++.h> 
using namespace std;

class Power{
    public:
    // Brute Force
    long long brute(int x, int n){
        long long ans = 1;
        int nn = abs(n);

        for(int i = 0; i < nn; i++){
            ans *= x;
        }

        return ans;
    }

    // Iterative Binary Exponentiation
    long long binExpoIter(int x, int n){
        long long ans = 1.0;

        long long nn = n; 

        while(nn > 0){
            // odd power
            if(nn % 2 == 1){
                ans = ans * x;
                nn = nn - 1;
            }
            // // even power
            // else{
            //     x = x * x;
            //     nn = nn / 2;
            // }

            /*
                if nn becomes odd, then after nn = nn-1, nn becomes even automatically,
                and thus we save one extra iteration in iterations starting with odd nn
            */
            x = x * x; 
            nn = nn / 2;
        }

        return ans;
    }

    // Recursive Binary Exponentiation
    long long binExpoRec(long long x, int n){
        if(n == 0){
            return 1;
        }

        // odd power
        if(n%2 == 1){
            return x * binExpoRec(x * x, (n-1) / 2);
        }
        else{
            return binExpoRec(x * x, n / 2);
        }
    }
};

long long Pow(int x, int n){
    // Write your code here.

    if (n == 0) {
        return 1;
    }

    Power obj;

    //* Brute Force-> TC = O(N)
    // return obj.brute(x, n);

    //* Optimized-> using Binary Exponentiation Technique (Fast Exponentiation)
    // return obj.binExpoIter(x, n); // Binary Exponentiation Iterative
    return obj.binExpoRec((long long) x, n); // Binary Exponentiation Recursive
}