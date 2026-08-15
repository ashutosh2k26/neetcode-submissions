class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mapN;
        for(int i = 0 ; i < nums.size() ; i++) {
            mapN[nums[i]]++;
        }
        vector<int> ret;
        map<int,vector<int>> countMap;
        
        for(auto it : mapN) {
            countMap[it.second].push_back(it.first);
        }

        int t =0;
        for (auto it = countMap.rbegin(); it != countMap.rend() ; it++) {
            if(t > k) {
                break;
            } 

            auto itr = it->second;
            for( auto itrvec : itr) {
                if(t < k) {
                    ret.push_back(itrvec);
                    t++;
                } 
            }
        }
       

        return ret;
    }
};
