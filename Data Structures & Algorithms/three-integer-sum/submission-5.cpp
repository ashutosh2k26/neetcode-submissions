class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> visited;
        /// [-4 -1 -1 0 1 2 ]
        /// [0 0 0]
        vector<vector<int>> ret;
        int prev = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(prev == nums[i]) {
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            int target = 0 - nums[i];
            cout<<"target "<<target<<"\n";
            while(left < right) {
                int sum = nums[left] + nums[right];

                if( sum  == target ) {
                    vector<int> vec {nums[i],nums[left],nums[right]};
                    if(visited.find(vec) == visited.end()){
                        ret.push_back({nums[i],nums[left],nums[right]});
                        visited.insert(vec);
                    }
                }

                if(sum > target) {
                    right--;
                } else {
                    left++;
                }
            }

            prev = nums[i];
        }
        return ret;
    }
};
