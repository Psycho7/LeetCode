class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        bool flag = true;
        int p = n - 1;
        while (flag && p >=0) {
            digits[p] += 1;
            flag = digits[p] > 9;
            if (flag) {
                digits[p] -= 10;
                p--;   
            }
        }
        
        if (p < 0) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};