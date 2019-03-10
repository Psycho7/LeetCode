class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int n : nums) {
            map[n] = map[n] + 1;
        }
        
        priority_queue<pair<int, int>> heap;
        for (auto & kv : map) {
            heap.push(make_pair(kv.second, kv.first));
        }
        
        vector<int> result;
        while (k > 0) {
            result.push_back(heap.top().second);
            heap.pop();
            k--;
        }
        
        return result;
    }
};