#include <sstream>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (combine(nums[j], nums[i]) > combine(nums[i], nums[j])) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        
        if (nums.size() > 0 && nums[0] == 0) return "0";
        
        stringstream stream;
        for (int i = 0; i < nums.size(); i++) {
            stream << nums[i];
        }
        
        return stream.str();
    }
    
    long combine(long x, long y) {
        int tmp = y;
        do {
            tmp /= 10;
            x *= 10;
        } while (tmp > 0);
        return x + y;
    }
};