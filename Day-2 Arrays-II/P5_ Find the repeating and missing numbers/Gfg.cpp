//* https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//* https://www.youtube.com/watch?v=2D0D8HE6uak

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        
        FindNumbers obj;

    	//* Exterme Brute Force-> O(n^2)
    	// return obj.brute1(arr, n);
    
    	//* Brute Force-> TC-> O(n), SC-> O(n), using maps
    	// return obj.brute2(arr, n);
    
    	//* Optimal-> Using Maths-> TC->O(n), SC->O(1)
    	// return obj.optimal_Math(arr);
    
    	//* Optimal-> Using XOR-> TC->O(n), SC->O(1)
        return obj.optimal_XOR(arr);
    }
    
    class FindNumbers{
    public:
        vector<int> brute1(vector<int>& arr, int n){
            
            int missing, repeating;
    
            for(int i = 1; i <= n; i++){
    
                int cnt = 0;
                for(int j = 0; j < n; j++){
                    if(i == arr[j]){
                        cnt++;
                    }
                }
    
                if(cnt == 0){
                    missing = i;
                }
                if(cnt > 1){
                    repeating = i;
                }
            }
    
            return {repeating, missing};
        }
    
        vector<int> brute2(vector<int>& arr, int n){

            int missing, repeating;
            unordered_map<int,int> freq;
    
            for(int i = 0; i < n; i++){
                freq[arr[i]]++;
            }
    
            for(int num = 1; num <= n; num++){
                if(freq[num] == 0) missing = num;
                if(freq[num] > 1) repeating = num;
            }
    
            return {repeating, missing};
        }
    
        vector<int> optimal_Math(vector<int>& arr){
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

            return {(int)x, (int)y};
        }

        vector<int> optimal_XOR(vector<int>& a){
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
            if (cnt == 2) return {zero, one};
            return {one, zero};
        }
    };
};