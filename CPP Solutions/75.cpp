class Solution {
public:
    void sortColors(vector<int>& nums) {
        int key = 1;
        
        int i = 0, pos = 0;
        int j = nums.size() - 1;
        
        while (pos <= j) {
            if (nums[pos] < key) {
                swap(nums[i], nums[pos]);
                i++;
                pos++;
            } else if (nums[pos] == key) {
                pos++;
            } else if (nums[pos] > key) {
                swap(nums[pos], nums[j--]);
            }
        }
    }
};