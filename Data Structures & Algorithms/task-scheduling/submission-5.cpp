class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mapCount;
        for(int i = 0 ; i < tasks.size() ; i++ ) {
            mapCount[tasks[i]]++;
        }

        std::priority_queue<int> pq;
        for(auto itr : mapCount) {
            pq.push(itr.second);
        }
        
        queue<vector<int>> que;
        int tm = 0;
        while(!pq.empty() || !que.empty()) {    
            if(!pq.empty()) {
                int tp = pq.top();
                if(tp-1 > 0) {
                    que.push(vector<int>{tp-1,tm+n+1});
                }
                pq.pop();
            }
            tm++;
            if(!que.empty() && que.front()[1] == tm) { 
                    pq.push(que.front()[0]);
                    que.pop();
            }
        }
        return tm;
    }
};
