class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<int> preSum(A.size() + 1, 0);
        preSum[0] = 0;
        for (int i = 1; i <= A.size(); i++) {
            preSum[i] = preSum[i - 1] + A[i - 1];
        }
        
        deque<int> tail;
        tail.push_back(0);
        int head = 1;
        int ans = INT_MAX;
        while (head <= A.size()) {
            while (!tail.empty() && (preSum[head] - preSum[tail.front()] >= K)) {
                ans = min(ans, head - tail.front());
                tail.pop_front();
            }
            while (!tail.empty() && (preSum[head] <= preSum[tail.back()])) {
                tail.pop_back();
            }
            tail.push_back(head);
            head++;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};