class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int head = 0, tail = nums.size();
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            if (nums[mid] < target) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        if (head >= nums.size() || nums[head] != target) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } else {
            ans.push_back(head);
        }
        
        head = 0, tail = nums.size();
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            if (nums[mid] <= target) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        ans.push_back(head - 1);
        
        return ans;
    }
};