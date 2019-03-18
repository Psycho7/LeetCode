class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> fmax(n, INT_MIN);
        vector<int> fmin(n, INT_MAX);
        
        fmax[0] = nums[0];
        fmin[0] = nums[0];
        
        int ans = nums[0];
        
        for (int i = 1; i < n; i++) {
            int minTemp = fmin[i - 1] * nums[i];
            int maxTemp = fmax[i - 1] * nums[i];
            
            fmax[i] = max(nums[i], max(minTemp, maxTemp));
            fmin[i] = min(nums[i], min(minTemp, maxTemp));
            
            ans = max(ans, fmax[i]);
        }
        
        return ans;
    }
};