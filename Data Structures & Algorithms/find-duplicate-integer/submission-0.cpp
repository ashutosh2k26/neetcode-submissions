class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> nMap;
        for(int i = 0 ; i < nums.size(); i++) {
            nMap[nums[i]]++;
            if(nMap[nums[i]] > 1) {
                return nums[i];
            }
            
        }
        return -1;
    }
};
