class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sn = 0;
        for (int v : nums) {
            sn = sn ^ v;
        }
        return sn;
    }
};