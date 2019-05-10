class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left  = 0, right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (mid + 1 == nums.size() || nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }   
        }
        return left;
    }
};