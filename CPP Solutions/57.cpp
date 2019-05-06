class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int x = 0;
        int y = 0;
        vector<int> tmp{-1, -1};
        auto newIntervals = vector<vector<int>>{ newInterval };
        while (x < intervals.size() || y < newIntervals.size()) {
            bool x_flag = (y == newIntervals.size()) 
                || (x < intervals.size() && intervals[x][0] <= newIntervals[y][0]);
            
            vector<int>& curv = x_flag ? intervals[x] : newIntervals[y];
            int& idx = x_flag ? x : y;
            
            if (curv[0] <= tmp[1]) {
                tmp[1] = max(tmp[1], curv[1]);
            } else {
                ans.push_back(tmp);
                tmp = curv;
            }
            
            idx++;
        }
        ans.push_back(tmp);
        ans.erase(ans.begin());
        
        return ans;
    }
};