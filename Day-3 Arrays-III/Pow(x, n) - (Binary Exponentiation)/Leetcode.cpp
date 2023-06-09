//* https://leetcode.com/problems/powx-n/
//* https://www.youtube.com/watch?v=l0YC3876qxg
//* https://leetcode.com/problems/powx-n/editorial/


class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) {
            return 1;
        }

        Power obj;

        //* Brute Force-> TC = O(N), gives TLE
        // return obj.brute(x, n);

        //* Optimized-> using Binary Exponentiation Technique (Fast Exponentiation)
        //* type caste to long long in order to avoid integer overflow while converting -ve n to +ve n
        // return obj.binExpoIter(x, (long long) n); // Binary Exponentiation Iterative
        return obj.binExpoRec(x, (long long) n); // Binary Exponentiation Recursive
    }

    class Power{
    public:
        // Brute Force gives TLE
        double brute(double x, int n){
            double ans = 1;
            int nn = abs(n);

            for(int i = 0; i < nn; i++){
                ans *= x;
            }

            return (n < 0 ? ((double)1 / ans) : ans);
        }

        // Iterative Binary Exponentiation
        double binExpoIter(double x, long long n){
            double ans = 1.0;

            // long long nn = abs(n);
            long long nn = n; 
            // simple modification in order to reduce last check at return statement
            if(nn < 0){
                nn = -1 * nn;
                x = 1.0 / x;
            }

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

            // return (n < 0 ? ((double)(1) / (double)(ans)) : ans);
            return ans;
        }

        // Recursive Binary Exponentiation
        double binExpoRec(double x, long long n){
            if(n == 0){
                return 1;
            }

            // case when n < 0
            if(n < 0){
                return 1.0 / binExpoRec(x, -1 * n);
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
};