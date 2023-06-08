//* https://www.codingninjas.com/codestudio/problems/699917
//* https://www.youtube.com/watch?v=IexN60k62jo

#include <bits/stdc++.h> 
using namespace std;

/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    
    vector<vector<int>> merged;
        
    int n = intervals.size();
    if(n == 0){
        return merged;
    }

    sort(intervals.begin(),intervals.end());

    for(int i = 0; i < n; i++){
        int start = intervals[i][0], end = intervals[i][1];

        if(merged.empty() || merged.back()[1] < start){
            merged.push_back({start, end});
        }
        else{
            merged.back()[1] = max(merged.back()[1], end);
        }
    }

    return merged;
}
