class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<vector<int>> visited;
        std::queue<vector<int>> que;
        int mx = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                    que.push({i,j});
                    bfs(grid, que, visited, mx);
                }
            }
        }
        return mx;
    }

    void bfs(vector<vector<int>>& grid, queue<vector<int>>& que, set<vector<int>>& visited,
             int& mx) {
        int size = 0;
        while (!que.empty()) {
            vector<int> vec = que.front();
            que.pop();
            if(visited.find(vec) == visited.end()) {
                visited.insert(vec);
                size++;
            }
            
            int x = vec[0];
            int y = vec[1];
            /// col
            if (y - 1 >= 0 && grid[x][y - 1] == 1 && visited.find({x, y - 1}) == visited.end()) {
                size++;
                visited.insert({x, y - 1});
                que.push({x, y - 1});
            }
            if (y + 1 < grid[0].size() && grid[x][y + 1] == 1 && visited.find({x, y + 1}) == visited.end()) {
                size++;
                visited.insert({x, y + 1});
                que.push({x, y + 1});
            }
            if (x - 1 >= 0 && grid[x-1][y] == 1 && visited.find({x-1, y}) == visited.end()) {
                size++;
                visited.insert({x-1, y});
                que.push({x-1, y});
            }
            if (x + 1 < grid.size() && grid[x+1][y ] == 1 && visited.find({x+1, y}) == visited.end()) {
                size++;
                visited.insert({x+1, y });
                que.push({x+1, y });
            }
        }
        cout<<"size "<<size<<"\n";
        mx = max(mx,size);
    }
};
