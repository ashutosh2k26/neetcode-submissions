class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        map<int,int> indegree;
        map<int,vector<int>> adjList;

        for(int i = 0 ; i < numCourses ; i++) {
            indegree[i] = 0;
        }
        
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            indegree[prerequisites[i][0]]++;
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> nodesWithZeroIndegree;
        for(auto itr : indegree) {
            if (itr.second == 0) {
                nodesWithZeroIndegree.push(itr.first);
            }
        }

        /// Cycle
        if(nodesWithZeroIndegree.size() == 0) {
            return false;
        } 

        vector<int> troVec;
        
        while(!nodesWithZeroIndegree.empty()) {
            int top = nodesWithZeroIndegree.front();
            nodesWithZeroIndegree.pop();
            troVec.push_back(top);


            std::cout<<"Till here\n";
            auto itr = adjList.find(top);
            if (itr != adjList.end()) {
                auto vec = itr->second;
                for(int i = 0 ;i <  vec.size() ; i++) {
                    indegree[vec[i]]--;
                    if(indegree[vec[i]] == 0) {
                        nodesWithZeroIndegree.push(vec[i]);
                    }
                }
            }
        }
    

        if(troVec.size() == numCourses) {
            return true;
        }

        return false;

    }
};
