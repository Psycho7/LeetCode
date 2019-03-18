class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findK(nums, nums.size() - k + 1, 0, nums.size());
    }
    
    int findK(vector<int>& nums, int k, int left, int right) {
        swap(nums[left], nums[(left+right)>>1]);
        
        int key = nums[left];
        int i = left + 1;
        int j = right - 1;
        while (i <= j) {
            while (i <= j && nums[i] < key) i++;
            while (i <= j && nums[j] >= key) j--;
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[left], nums[j]);
        
        int pos = j;
        
        int less = pos - left;
        if (k == less + 1) return nums[pos];
        if (k <= less) return findK(nums, k, left, pos);
        return findK(nums, k - less - 1, pos + 1, right);
    }
};