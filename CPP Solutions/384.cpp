class Solution {
public:
    Solution(vector<int> nums): nums(nums) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> f(nums);
        
        for (int i = 0; i < f.size(); i++) {
            int idx = rand() % (i+1);
            swap(f[i], f[idx]);
        }
        
        return f;
    }
    
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */