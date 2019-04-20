class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, vector<int>());
        vector<int> ind(numCourses, 0);
        queue<int> topo;
        int visit = 0;
        
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
            visit++;
            
            for (auto& k : edge[now]) {
                ind[k]--;
                if (ind[k] == 0) {
                    topo.push(k);
                }
            }
        }
        
        return visit == numCourses;
    }
};