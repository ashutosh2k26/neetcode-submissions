class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        std::vector<std::vector<int>> pos;//x,y 2 
        int row = grid.size();
        int col = grid[0].size();
        set<vector<int>> visited;

        for(int i = 0 ; i < row; i++) {
            for (int j = 0 ; j < col; j++) {
                if(grid[i][j] == 2){
                    pos.push_back(vector<int>{i,j});
                }
            }
        }

        std::queue<std::vector<int>> que;
        
        
        for(int i = 0 ; i < pos.size(); i++) {
            std::cout<<"pos[i][0] "<<pos[i][0]<<" pos[i][1] "<<pos[i][1]<<"\n";
            que.push(pos[i]);
            visited.insert(pos[i]);
        }

        int tm = 0;
        int maxElePerLevel = pos.size();

        while(!que.empty()) {
            int ele = 0;
            for(int i = 0 ; i < maxElePerLevel && !que.empty(); i++) {
                std::vector<int> top = que.front();
                que.pop();

                if(top[0] - 1 >= 0 && grid[top[0]-1][top[1]] == 1) {
                    std::vector<int> np {top[0] -1,top[1]};
                    cout<<"np "<<np[0]<<" np[1] "<<np[1]<<"\n";
                    if(visited.find(np) == visited.end()) {
                        cout<<"insert\n";
                        visited.insert(np);
                        que.push(np);
                        grid[top[0]-1][top[1]] = 2;
                        ele++;
                    }
                }

                if(top[0] + 1 < row && grid[top[0] +1][top[1]] == 1) {
                    vector<int> np {top[0] + 1,top[1]};
                    if (visited.find(np) == visited.end()) {
                        visited.insert(np);
                        que.push(np);
                        grid[top[0]+1][top[1]] = 2;
                        ele++;
                    }
                }

                if(top[1] -1 >=  0 && grid[top[0]][top[1]- 1] == 1) {
                    vector<int> np {top[0], top[1] -1};
                    if(visited.find(np) == visited.end()) {
                        visited.insert(np);
                        que.push(np);
                        grid[top[0]][top[1]-1] = 2;
                        ele++;
                    }
                }

                if(top[1] + 1 < col && grid[top[0]][top[1]+1] == 1) {
                    vector<int> np { top[0], top[1]+1};
                    if(visited.find(np) == visited.end()) {
                        visited.insert(np);
                        que.push(np);
                        grid[top[0]][top[1]+1] = 2;
                        ele++;
                    }
                }
            }
        
            maxElePerLevel = ele;
            if (ele != 0) {
                tm++;
            }
    
        }

        for(int i = 0 ; i < row ; i++) {
            for(int j = 0 ; j < col; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return tm;
    }
};
