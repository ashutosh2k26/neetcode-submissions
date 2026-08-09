class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        std::queue<int> que; 
        map<int,vector<int>> adjList;
        map<int,int> indegree;
  
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i = 0 ; i < numCourses; i++) {
            if(indegree.find(i) == indegree.end()) {
                //std::cout<<"i "<<i<<"\n";
                que.push(i);
            }
        }
        
        
        for(auto itr : indegree) {
            //std::cout<<"indegree "<<itr.first<<" count"<<itr.second<<"\n";
        }
        

        if(que.empty()) {
            //std::cout<<"que empty\n";
            return order;
        }

        while(!que.empty()) {
            int front = que.front();
            que.pop();
            order.push_back(front);
            //std::cout<<"item pushed "<<front<<" order size "<<order.size()<<"\n";

            auto itr = adjList.find(front);
            if(itr != adjList.end()) {
                //std::cout<<"Found\n";
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
