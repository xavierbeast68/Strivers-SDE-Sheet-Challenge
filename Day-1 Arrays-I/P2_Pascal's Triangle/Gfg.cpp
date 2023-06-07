//* https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1
//* https://youtu.be/bR7mQgwQ_o8


#define ll long long int
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
    
        //* Optimal Approach-> O(n^2)
        Optimal op;
        return op.generateRow(n);
    }
    
    
    //* Optimal Approach->
    class Optimal{
    public:
        vector<ll> generateRow(int row){
        
            ll mod = 1e9+7;
            
            ll ans = 1;
            vector<ll> ansRow{1};
    
            for(int col = 1; col < row; col++){
                
                ans = (ans * (row-col)) % mod;
                ans = (ans * modInverse(col, mod)) %mod;
                
                ansRow.push_back(ans);
                
                /*
                *   Modified Striver's Approach->
                    
                    Those who are facing problem with the 50th test case it's beacuse 
                    "ans = ((ans/col)%mod )" will not work always, 
                    as ((ans/col)%mod) is not equal to ((ans%mod)*(col%mod)%mod).
                    It is actually equal to ((ans%mod)*(col^-1%mod)%mod).
                    
                    Therefore to make this approach to work for all the test cases, 
                    you have to take the modulo multiplicative inverse of col. 
                    Modinverse function takes 1e9+7 and col as input and 
                    returns the modulo multiplicative inverse of col.
                */
                
            }
    
            return ansRow;
        }
        private:
            long long modInverse(long long a, long long m) {
                long long m0 = m;
                long long y = 0, x = 1;
                if (m == 1)
                    return 0;
                while (a > 1) {
                    long long q = a / m;
                    long long t = m;
                    m = a % m, a = t;
                    t = y;
                    y = x - q * y;
                    x = t;
                }
                if (x < 0)
                    x += m0;
                return x;
            }
    };
};