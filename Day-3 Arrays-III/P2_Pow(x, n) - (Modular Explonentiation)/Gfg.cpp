//* https://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1
//* https://www.youtube.com/watch?v=l0YC3876qxg
//* https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M){
		    // Code here

            return modExpo(x, n, M);
		}
		
		long long modExpo(long long x, long long n, long long mod){
            long long ans = 1;
        
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
};