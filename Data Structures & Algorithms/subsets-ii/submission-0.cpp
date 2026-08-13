class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sets;
        sort(nums.begin(),nums.end());
        Subsets(nums,0,sets);
        return ret;        
    }
    void Subsets(vector<int>& nums,int index,vector<int> sets) {
        if(index == nums.size()) {
            if(dup.find(sets) == dup.end()) {
                ret.push_back(sets);
                dup.insert(sets);
            }
            return;
        }

        sets.push_back(nums[index++]);
        Subsets(nums,index,sets);
        sets.pop_back();
        Subsets(nums,index,sets);
    }

    vector<vector<int>> ret;
    set<vector<int>> dup;
};
