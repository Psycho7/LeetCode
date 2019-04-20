class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return vector<vector<int>>();
        
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });
        
        vector<vector<int>> ans;
        int low = intervals[0][0], high = intervals[0][1];
        for (auto& interval : intervals) {
            if (interval[0] > high) {
                ans.push_back(vector<int>{ low, high });
                low = interval[0];
                high = interval[1];
            } else {
                high = max(high, interval[1]);
            }
        }
        ans.push_back(vector<int>{ low, high });
        return ans;
    }
};