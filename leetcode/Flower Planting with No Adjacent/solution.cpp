class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> res(n, 0);
        unordered_map<int, vector<int>> umap;
        
        // We create our adjacency list.
        for (auto& path : paths) {
            // Bi-directional graph.
            umap[path[0]].push_back(path[1]);
            umap[path[1]].push_back(path[0]);
        }
        
        // Perform a BFS but with coloring.
        // Self-assign node 1 with color 1.
        queue<int> q;
        
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            // Check if already visited and set.
            if (res[v - 1] != 0) {
                continue;
            }
            
            int colors[5] = { 0, 1, 2, 3, 4 };
            
            for (int i = 0; i < umap[v].size(); i++) {
                colors[res[umap[v][i] - 1]] = 0;
            }
            
            for (int i = 0; i < 5; i++) {
                if (colors[i] != 0) { 
                    res[v - 1] = colors[i];
                    break;
                }
            }
            
        }
        
        return res;
    }
};