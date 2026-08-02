class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int left  = 1;
        int right = piles[piles.size()-1];
        int mid = (left + right)/2;

        vector<int> res;
        while(left <= right) {
            long t = 0;

            for (int i = 0 ; i < piles.size() ; i++) {
                t += (piles[i] + mid -1)/mid; 
            }
            if (t <=  h ) {
                res.push_back(mid);
                right = mid -1;
                mid = (left + right)/2;
            } else {
                left = mid+1;
                mid = (left+right)/2;
            }
        }
        sort(res.begin(),res.end());
        return res[0];
    }
};
