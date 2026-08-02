class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> nmaps;
        for(auto it : nums) {
            if(nmaps.find(it) == nmaps.end()){
                nmaps[it] = 1;
            } else {
                return true;
            }
        }
        return false;
    }
};