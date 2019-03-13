class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        
        int head = 0, tail = len;
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            int cnt = 0;
            for (auto& n : nums) {
                if (n <= mid) cnt++;
            } 
            if (cnt <= mid) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        
        return head;
    }
};