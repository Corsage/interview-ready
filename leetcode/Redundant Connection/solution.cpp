class Solution {
public:

    int findParent(int v, vector<int>& parents) {
        int res = parents[v];
        
        while (res != parents[res]) {
            parents[res] = parents[parents[res]];
            res = parents[res];
        }
        
        return res;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        int n = edges.size();
        
        // Keep track of graph rank and parent vertex.
        // A vertex with no edges has a default rank of 1.
        vector<int> ranks(n + 1, 1);
        
        // A vertex with no edges is default itself as a parent.
        vector<int> parents(n + 1);
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
        }
        
        for (auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            // If vertices have the same parent, it is a
            // redundant connection as a path from x -> y
            // already exists.
            int xp = findParent(x, parents);
            int yp = findParent(y, parents);
            
            if (xp == yp) {
                res[0] = x;
                res[1] = y;
                break;
            }
            
            // They have different parents, we merge the smaller
            // rank to the larger one via union.
            if (ranks[xp] >= ranks[yp]) {
                parents[yp] = xp;
                ranks[xp] += ranks[yp];
            } else {
                parents[xp] = yp;
                ranks[yp] += ranks[xp];
            }
        }
        
        return res;
    }

    /**
     * Find the union of two sets.
     * If two elements are already in the same set,
     * it will cause a cycle.
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        vector<unordered_set<int>> usets;
        
        for (auto& edge : edges) {
            int ia = -1;
            int ib = -1;
            
            // Search for vertex.
            for (int i = 0; i < usets.size(); i++) {
                if (usets[i].find(edge[0]) != usets[i].end()) {
                    ia = i;
                }
                
                if (usets[i].find(edge[1]) != usets[i].end()) {
                    ib = i;
                }
            }
            
            if (ia == -1 & ib == -1) {
                usets.push_back(unordered_set<int> { edge[0], edge[1] });
            } else if (ia == ib) {
                res[0] = edge[0];
                res[1] = edge[1];
                break;
            } else {
                if (ia == -1) {
                    usets[ib].insert(edge[0]);
                } else if (ib == -1) {
                    usets[ia].insert(edge[1]);
                } else {
                    // Merge the two sets.
                    for (auto& v : usets[ib]) {
                        usets[ia].insert(v);
                    }
                    usets.erase(usets.begin() + ib);
                }
            }
        }
        
        return res;
    }
    
    bool isCycle(unordered_map<int, unordered_set<int>>& umap, int start, int vertex, int depth, vector<bool>& visited) {
        //cout << "isCycle with start: " << start << " and vertex: " << vertex << " and depth: " << depth << endl;
        
        if (depth > 2 && umap[vertex].find(start) != umap[vertex].end()) {
            return true;
        }
        
        visited[vertex] = true;
        
        for (auto& v : umap[vertex]) {
            if (v != start && !visited[v]) {
                if (isCycle(umap, start, v, depth + 1, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        unordered_map<int, unordered_set<int>> umap;
        
        // By definition, a connected undirected graph with n vertices and k edges
        // must be strictly n > k to have no cycles present.
        //
        // However, we cannot ensure it is connected as we add edges one-by-one.
        // It is known only the final graph is connected.
        for (auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            
            // Add edges to search.
            umap[a].insert(b);
            umap[b].insert(a);
            
            vector<bool> visited(1001);
            
            // cout << "trying " << endl;
             if (isCycle(umap, a, a, 1, visited)) {
                res[0] = a;
                res[1] = b;
                break;
            }
            
        }
        
        return res;
    }
};