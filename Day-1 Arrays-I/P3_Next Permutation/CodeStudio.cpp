//* https://www.codingninjas.com/codestudio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
//* https://youtu.be/JDOXKqF60RQ

#include <bits/stdc++.h> 
using namespace std;

vector<int> nextPermutation(vector<int> &permutation, int N){
    //  Write your code here.

    if (N == 1){
        return permutation;
    }

    // find index i such that arr[i] < arr[i+1]
    int ind = -1;
    for(int i = N-2; i >= 0; --i){
        if (permutation[i] < permutation[i + 1]){
            ind = i;
            break;
        }
    }

    // if no such index found, means to reverse the whole permutation
    if (ind == -1){
        reverse(begin(permutation), end(permutation));
        return permutation;
    }

    // find index of i from back such that arr[i] is just > arr[ind]
    for(int i = N-1; i >= 0; --i)
    {
        if (permutation[i] > permutation[ind]){
            // swapping->
            swap(permutation[i], permutation[ind]);
            break;
        }
    }


    // reverse from ind+1 till end
    reverse(permutation.begin() + (ind + 1), permutation.end());

    return permutation;
}