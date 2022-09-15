class Solution {
public:

    void dfs(vector<vector<char>>& grid, unordered_set<int>& visited, int i, int j) {
        // Map the (i, j) to a single number.
        int num = grid[0].size() * i + j;
        visited.insert(num);
        
        // Check right vertex.
        if (j + 1 < grid[0].size()) {
            if (grid[i][j + 1] == '1' && visited.find(num + 1) == visited.end()) {
                dfs(grid, visited, i, j + 1);
            }
        }
        
        // Check left vertex.
        if (j - 1 >= 0) {
            if (grid[i][j - 1] == '1' && visited.find(num - 1) == visited.end()) {
                dfs(grid, visited, i, j - 1);
            }
        }
        
        // Check top vertex.
        if (i - 1 >= 0) {
            if (grid[i - 1][j] == '1' && visited.find(num - grid[0].size()) == visited.end()) {
                dfs(grid, visited, i - 1, j);
            }
        }
        
        // Check bottom vertex.
        if (i + 1 < grid.size()) {
            if (grid[i + 1][j] == '1' && visited.find(num + grid[0].size()) == visited.end()) {
                dfs(grid, visited, i + 1, j);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        unordered_set<int> visited;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int num = grid[0].size() * i + j;
                if (grid[i][j] == '1' && visited.find(num) == visited.end()) {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }

    int numIslands(vector<vector<char>>& grid) {
        // Graph theory: Count the number of components in a graph.
        // An undirected graph with no cycles has V - E components.
        // Because each component is a tree with N vertices and N - 1 edges.
        vector<unordered_set<int>> usets;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    int num = i * grid[i].size() + j;
                
                    // Check left or above.
                    int left = -1;
                    int above = -1;
                    int range = usets.size() - grid[i].size();
                    if (range < 0) { range = 0; }
                    for (int k = usets.size() - 1; k >= range; k--) {
                        if (j > 0 && usets[k].find(num - 1) != usets[k].end()) {
                            left = k;
                        }
                        
                        if (i > 0 && usets[k].find(num - grid[i].size()) != usets[k].end()) {
                            above = k;
                        }
                        
                        if (left != -1 && above != -1) {
                            break;
                        }
                    }
                    
                    if (left == -1 && above == -1) {
                        usets.push_back(unordered_set<int> { num });
                    } else if (left == above) {
                        usets[left].insert(num);
                    } else if (left == -1) {
                        usets[above].insert(num);
                    } else if (above == -1) {
                        usets[left].insert(num);
                    } else {
                        // Connect two components.
                        usets[left].insert(usets[above].begin(), usets[above].end());
                        usets[left].insert(num);
                        usets.erase(usets.begin() + above);
                    }
                }
            }
        }
        
        return usets.size();
    }
};