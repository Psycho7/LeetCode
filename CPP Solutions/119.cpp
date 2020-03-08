class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr[2];
        arr[0].push_back(1);
        int cur = 0;
        for (int i = 1; i <= rowIndex; i++) {
            int next = cur ^ 1;
            
            arr[next].push_back(1);
            for (int j = 1; j < i; j++) {
                arr[next].push_back(arr[cur][j-1] + arr[cur][j]);
            }
            arr[next].push_back(1);
            
            arr[cur].clear();
            cur = next;
        }
        return arr[cur];
    }
};