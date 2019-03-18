class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) return nums[0] == target ? 0 : -1;
        
        int pivot = findPivot(nums);
        cout << pivot << endl;
        
        int head = 0, tail = pivot;
        if (target < nums[0]) {
            head = pivot;
            tail = nums.size();
        }
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        return -1;
    }
    
    int findPivot(vector<int>& f) {
        int head = 1, tail = f.size();
        
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            
            if (f[mid] > f[0]) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        
        return head;
    }
};