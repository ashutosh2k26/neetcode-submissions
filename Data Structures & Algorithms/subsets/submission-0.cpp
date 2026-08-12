class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sets{};
        Subsets(nums,0,sets);
        return rets;
        
    }
    void Subsets(vector<int> &nums, int index,vector<int> sets){
        if (index == nums.size()) {
            rets.push_back(sets);
            return ;
        }
        
        sets.push_back(nums[index++]);
        Subsets(nums,index,sets);
        sets.pop_back();
        Subsets(nums,index,sets);
    }
    
    vector<vector<int>> rets;
};
