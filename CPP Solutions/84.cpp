class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int len = heights.size();
        if (len == 0) return 0;
        
        stack<int> st;
        heights.push_back(0);
        for (int i = 0; i <= len; i++) {
            int cur = heights[i];
            if (st.empty() || cur >= heights[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && cur < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int left = st.empty() ? -1 : st.top();
                    int tmp = h * (i - 1 - left);
                    if (tmp > ans) {
                        ans = tmp;
                    }
                }
                st.push(i);
            }
        }
        
        return ans;
    }
};
