class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string,vector<string>> ms;
        for(int i = 0 ; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(),key.end());
            if(ms.find(key) == ms.end()) {
                ms[key] = vector<string>{strs[i]};
            } else
                ms[key].push_back(strs[i]); 
        }

        for(auto itr : ms) {
            ret.push_back(itr.second);
        }
        return ret;

    }
};
