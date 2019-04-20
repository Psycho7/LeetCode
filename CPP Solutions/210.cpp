class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        
        vector<vector<int>> edge(numCourses, vector<int>());
        vector<int> ind(numCourses, 0);
        queue<int> topo;
        
        for (auto& pair: prerequisites) {
            edge[pair.second].push_back(pair.first);
            ind[pair.first]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) {
                topo.push(i);
            }
        }
        
        while (!topo.empty()) {
            int now = topo.front();
            topo.pop();
            ans.push_back(now);
            
            for (auto& k : edge[now]) {
                ind[k]--;
                if (ind[k] == 0) {
                    topo.push(k);
                }
            }
        }
        
        if (ans.size() < numCourses) ans.clear();
        return ans;
    }
};