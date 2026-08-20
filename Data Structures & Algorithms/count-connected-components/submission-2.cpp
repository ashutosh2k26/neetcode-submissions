class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> gr;
        for (int i = 0; i < n; i++) {
            gr[i].push_back({});
        }
        for (int i = 0; i < edges.size(); i++) {
            for (int j = 0; j < 2; j++) {
                gr[edges[i][0]].push_back(edges[i][1]);
                gr[edges[i][1]].push_back(edges[i][0]);
            }
        }
        /*
            map[0] -> 1
            map[1] -> 0, 2
            map[3] -> 4
            map[4] -> 3
        */

        int comp = 0;
        set<int> visited;
        queue<int> que;
        for (auto it : gr) {
            int from = it.first;
            ///cout<<"from\n";
            if (visited.find(from) == visited.end()) {
                /// 0
                comp++;
                que.push(from);  /// 0
                bfs(gr, que, visited);
            }
        }
        return comp;
    }

    void bfs(map<int, vector<int>>& gr, queue<int>& que, set<int>& visited) {
        while (!que.empty()) {
            int front = que.front();  /// 0
            cout<<"front "<<front<<"\n";
            visited.insert(front);
            que.pop();

            auto vec = gr[front];

            for (int i = 0; i < vec.size(); i++) {
                int ov = vec[i];  // 1
                cout<<"ov "<<ov<<"\n";
                if (visited.find(ov) == visited.end()) {
                    que.push(ov);
                    visited.insert(ov);
                }
            }
        }
    }
};
