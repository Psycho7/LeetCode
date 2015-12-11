class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int i1 = 0;
        int i2 = 0;
        while ( i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] < nums2[i2]) {
                v.push_back(nums1[i1++]);
            } else {
                v.push_back(nums2[i2++]);
            }
        }
        while (i1 < nums1.size()) {
            v.push_back(nums1[i1++]);
        }
        while (i2 < nums2.size()) {
            v.push_back(nums2[i2++]);
        }
        int size = v.size();
        if (size == 0) {
            return 0.0;
        }
        if (size & 1 == 1) {
            return 1.0 * v[size >> 1];
        } else {
            return 0.5 * (v[size >> 1] + v[(size >> 1) - 1]);
        }
        
    }
};