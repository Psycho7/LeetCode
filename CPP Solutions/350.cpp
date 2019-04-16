class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> dict;
        for (auto n : nums1) {
            dict[n] = dict[n] + 1;
        }
        for (auto n : nums2) {
            if (dict[n] > 0) {
                result.push_back(n);
                dict[n] = dict[n] - 1;
            }
        }
        return result;
    }
};