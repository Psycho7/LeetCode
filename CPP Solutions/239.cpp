class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty()) {
            return result;
        }
        
        deque<int> list;
        for (int i = 0; i < nums.size(); i++) {
            if (!list.empty() && list.front() <= i - k) {
                list.pop_front();
            }
            while (!list.empty() && nums[list.back()] <= nums[i]) {
                list.pop_back();
            }
            list.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[list.front()]);
            }
        }
        
        return result;
    }
};