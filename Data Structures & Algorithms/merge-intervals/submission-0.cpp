class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> m;
        m.push_back(intervals[0]);
        for(int i = 1 ; i < intervals.size(); i++) {
            if(intervals[i][0] > m.back()[1] ) {
                m.push_back(intervals[i]);
            }
            m.back()[1] = max(m.back()[1],intervals[i][1]);
        }
        return m;    
    }
};
