class Solution {
public:
    
    int bfs(vector<vector<int>>& grid, unordered_set<int>& visited, int i, int j) {
        int size = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            int num = p.first * grid[0].size() + p.second;
            if (visited.find(num) != visited.end()) {
                continue;
            }
            
            visited.insert(num);
            size++;
            
            // Check left.
            if (p.second - 1 >= 0 && grid[p.first][p.second - 1] == 1 && visited.find(num - 1) == visited.end()) {
                q.push({p.first, p.second - 1});
            }
            
            // Check right.
            if (p.second + 1 < grid[0].size() && grid[p.first][p.second + 1] == 1 && visited.find(num + 1) == visited.end()) {
                q.push({p.first, p.second + 1});
            }
            
            // Check up.
            if (p.first - 1 >= 0 && grid[p.first - 1][p.second] == 1 && visited.find(num - grid[0].size()) == visited.end()) {
                q.push({p.first - 1, p.second});
            }
            
            // Check down.
            if (p.first + 1 < grid.size() && grid[p.first + 1][p.second] == 1 && visited.find(num + grid[0].size()) == visited.end()) {
                q.push({p.first + 1, p.second});
            }
        }
        
        return size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        unordered_set<int> visited;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                int num = i * grid[0].size() + j;
                    
                if (grid[i][j] == 1 && visited.find(num) == visited.end()) {
                    int size = bfs(grid, visited, i, j);
                    res = max(res, size);
                }
            }
        }
        
        return res;
    }
};