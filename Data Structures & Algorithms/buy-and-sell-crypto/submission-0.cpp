class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mn = INT_MAX;
        int mx = 0;
        int st = 0;
        for(int i = 0 ; i < prices.size() ; i++) {
            if( prices[i] < prices[st]) {
                mn = prices[st];
                st = i;
            } else {
                mx = max(mx,prices[i]- prices[st]);
            }

        }
        return mx;
        
    }
};
