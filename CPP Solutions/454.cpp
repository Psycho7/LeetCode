class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mapAB, mapCD;
        
        int n = A.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sumAB = A[i] + B[j];
                if (mapAB.count(sumAB) == 0) {
                    mapAB[sumAB] = 1;
                } else {
                    mapAB[sumAB] = mapAB[sumAB] + 1;
                }
                
                int sumCD = C[i] + D[j];
                if (mapCD.count(sumCD) == 0) {
                    mapCD[sumCD] = 1;
                } else {
                    mapCD[sumCD] = mapCD[sumCD] + 1;
                }
            }
        }
        
        int ans = 0;
        for (auto& kv : mapAB) {
            if (mapCD.count(-kv.first)) {
                ans += kv.second * mapCD[-kv.first];
            }
        }
        
        return ans;
    }
};