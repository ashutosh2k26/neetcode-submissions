class Solution {
public:
    int search(vector<int>& nums, int target) {
        // [3 4 5 6 0 1 2]
        // mid = 3 >6 
        // [3 4 5 6 0 1] 
        // [1 3 5]
        int low = 0;
        int high = nums.size() -1;
        int mid = (low + high)/2;

        while(low <= high) {
            if(nums[mid] == target) {
                return mid;
            }

            /// Left is sorted
            if(nums[mid] >= nums[low]) {
                if(nums[low] <= target && target < nums[mid]){
                    high = mid-1;
                } else {
                    low  = mid+1;
                }
            } else { /// right is sorted
                if(nums[mid] < target && target <=  nums[high] ) {
                    low = mid+1;
                } else {
                    high  = mid-1;
                }
            }

            mid = (low+high)/2;

        }
        return -1;
    }
};
