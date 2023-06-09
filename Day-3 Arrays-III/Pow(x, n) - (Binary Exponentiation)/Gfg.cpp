//* https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1
//* https://www.youtube.com/watch?v=l0YC3876qxg
//* https://leetcode.com/problems/powx-n/editorial/
//* https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number

class Solution{
public:
    // mod = 1e9 + 7 is laready defined in the driver code
    //You need to complete this fucntion
    
    long long power(int N,int R){
       //Your code here
        
        Power obj;

        //* Brute Force-> TC = O(N)
        // return obj.brute(N, R);
    
        //* Optimized-> using Binary Exponentiation Technique (Fast Exponentiation)
        // return obj.binExpoIter(N, R); // Binary Exponentiation Iterative
        return obj.binExpoRec(N, R); // Binary Exponentiation Recursive
    }
    
    class Power{
        public:
        // Brute Force
        long long brute(long long x, long long n){
            long long ans = 1;
            long long nn = abs(n);
    
            for(int i = 0; i < nn; i++){
                ans = (ans*x) % mod;
            }
    
            return ans;
        }
    
        // Iterative Binary Exponentiation
        long long binExpoIter(long long x, long long n){
            long long ans = 1.0;
            x = x % mod; // incase if x is already at an edge of overflowing
            long long nn = n; 
    
            while(nn > 0){
                // odd power
                if(nn % 2 == 1){
                    ans = ((ans%mod) * (x%mod)) % mod;
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
                x = ((x%mod) * (x%mod)) % mod; 
                nn = nn / 2;
            }
    
            return (ans)%mod;
        }
    
        // Recursive Binary Exponentiation
        long long binExpoRec(long long x, long long n){
            
            if(n == 0){
                return 1;
            }
    
            // odd power
            if(n%2 == 1){
                return ((x%mod) * (binExpoRec(((x%mod) * (x%mod))%mod, (n-1) / 2) % mod)) % mod;
            }
            else{
                return binExpoRec(((x%mod) * (x%mod))%mod, n / 2);
            }
        }
    };
};