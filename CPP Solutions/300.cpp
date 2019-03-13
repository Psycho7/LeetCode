class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> f(nums.size() + 1, INT_MIN);
        int len = 0;
        for (int k = 0; k < nums.size(); k++) {
            int head = 0, tail = len;
            while (head < tail) {
                int mid = head + (tail - head) / 2;
                if (f[mid] < nums[k]) {
                    head = mid + 1;
                } else {
                    tail = mid;
                }
            }
            f[head] = nums[k];
            if (head == len) len++;
        }
        return len;
    }
};