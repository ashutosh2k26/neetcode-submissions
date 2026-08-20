class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;

        int low = 0;
        int high = heights.size() -1;

        while(low < high) {
            int mn = min(heights[low], heights[high]);
            mx = max(mx,mn*(high - low));
            if(heights[low] > heights[high]){
                high--;
            } else {
                low++;
            }
        }
        return mx;
    }
};
