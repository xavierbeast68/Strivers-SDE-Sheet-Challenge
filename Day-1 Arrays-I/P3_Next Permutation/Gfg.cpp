//* https://practice.geeksforgeeks.org/problems/next-permutation5226/1
//* https://youtu.be/JDOXKqF60RQ

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        

        if (N == 1){
            return arr;
        }

        // find index i such that arr[i] < arr[i+1]
        int ind = -1;
        for(int i = N-2; i >= 0; --i){
            if (arr[i] < arr[i + 1]){
                ind = i;
                break;
            }
        }

        // if no such index found, means to reverse the whole permutation
        if (ind == -1){
            reverse(begin(arr), end(arr));
            return arr;
        }

        // find index of i from back such that arr[i] is just > arr[ind]
        for(int i = N-1; i >= 0; --i)
        {
            if (arr[i] > arr[ind]){
                // swapping->
                swap(arr[i], arr[ind]);
                break;
            }
        }


        // reverse from ind+1 till end
        reverse(arr.begin() + (ind + 1), arr.end());
        
        return arr;
    }
};