class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int temp = -1;
        
        for (auto n : nums) {
            if (count == 0) {
                temp = n;
                count = 1;
                continue;
            }
            if (n == temp) {
                count++;
            } else {
                count--;
            }
        }
        
        return temp;
    }
};