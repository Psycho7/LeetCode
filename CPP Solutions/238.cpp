class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> begin(n, 1);
        vector<int> end(n, 1);
        
        begin[0] = nums[0];
        end[n - 1] = nums[n - 1];
        for (int i = 1; i < n - 1; i++) {
            begin[i] = begin[i - 1] * nums[i];
            end[n - 1 - i] = end[n - i] * nums[n - 1 - i];
        }
        
        vector<int> result(n, 1);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                result[i] *= begin[i - 1];
            }
            if (i < n - 1) {
                result[i] *= end[i + 1];
            }
        }
        
        return result;
    }
};