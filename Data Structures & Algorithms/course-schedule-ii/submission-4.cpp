class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        std::queue<int> que; 
        map<int,vector<int>> adjList;
        map<int,int> indegree;  /// indegree count good for queue insertion
  
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            /// This is tricky to get here you need to create a mapping 
            /// from prerequisites[i][1] > prerequisites[i][0]
            /// because this is how the graph will take place 
            /// for example if prerequisites [1, 0] this means from 0 there is edge to 1
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i = 0 ; i < numCourses; i++) {
            if(indegree.find(i) == indegree.end()) {
                que.push(i);
            }
        }
    

        if(que.empty()) {
            return order;
        }

        while(!que.empty()) {
            int front = que.front();
            que.pop();
            order.push_back(front);
            auto itr = adjList.find(front);
            if(itr != adjList.end()) {
                /// Decrease the vertices indices by 1 which are directly coonected 
                /// by this vertex which has 0 indegree 
                /// if the vertex becomes 0 push it 
                for (int i = 0 ; i < itr->second.size() ; i++) {
                    indegree[itr->second[i]]--;
                    if(indegree[itr->second[i]] == 0) {
                        que.push(itr->second[i]);
                    }
                }
            }

        }

        if(order.size() == numCourses) {
            //sort(order.begin(),order.end());
            return order;
        }
        
        return vector<int>{};
    }
};
