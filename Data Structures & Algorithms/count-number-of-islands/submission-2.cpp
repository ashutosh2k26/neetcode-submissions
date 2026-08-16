class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        queue<vector<int>> que;
        vector<vector<bool>> visited(grid.size(),std::vector<bool>(grid[0].size(),false));
        int comp = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    comp++;
                    que.push({i, j});
                    visited[i][j] = true;
                    bfs(grid, que,visited);
                }
            }
        }
        return comp;
    }
    void bfs(vector<vector<char>>& grid, queue<vector<int>>& que,vector<vector<bool>> &visited) {
        while (!que.empty()) {
            vector<int> fr = que.front();
            int i = fr[0];
            int j = fr[1];
            //visited[i][j] = true;
            que.pop();

           
            if (i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == false) {
                que.push({i - 1, j});
                visited[i-1][j] = true;
            }
            if (i + 1 < grid.size() && grid[i + 1][j] == '1' &&
                visited[i + 1][j] == false) {
                que.push({i + 1, j});
                visited[i+1][j] = true;
            }
            if (j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == false) {
                que.push({i, j - 1});
                visited[i][j-1] = true;
            }
            if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' &&
                visited[i][j + 1] == false) {
                que.push({i, j + 1});
                visited[i][j+1] = true;
            }
        }
    }
};
