class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i = 0 ; i < nums.size(); i++) {
        //     for(int j = 0 ; j < nums.size(); j++) {
        //         if ( i == j){
        //             continue;
        //         }
        //         if (nums[i] + nums[j] == target) {
        //             return vector<int>{i,j};
        //         }
        //     }
        // }

        map<int,vector<int>> numIndex;
        for(int i = 0 ; i < nums.size(); i++) {
            numIndex[nums[i]].push_back(i);
        }

        // for(auto itr : numIndex) {
        //     //cout<<"nums "<<itr.first<<"\n";
        //     //for(auto it : itr.second) {
        //     //    cout<<"vector index "<<it<<"\n";
        //     //}
        // }

        for(int i = 0 ; i < nums.size(); i++) {
            //cout<<"i "<<i<<"\n";
            int another = target - nums[i];
            auto itr = numIndex[another];
            for(int j = 0 ; j < itr.size(); j++) {
                if( i == itr[j]) {
                    continue;
                } else {
                    if (i > itr[j]) {
                        return vector<int> {itr[j],i};
                    } else {
                        return vector<int> {i,itr[j]};
                    }
                }


            }
        }
        
    }
};
