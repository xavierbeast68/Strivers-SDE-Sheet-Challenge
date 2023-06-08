//* https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
//* https://www.youtube.com/watch?v=IexN60k62jo

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // Code here
        
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
};