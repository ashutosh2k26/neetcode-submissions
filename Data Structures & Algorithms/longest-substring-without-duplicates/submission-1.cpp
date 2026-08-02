class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int st = 0, en = 0;
        int mx = 0;
        map<char,int> mp;
        for(en = 0 ; en < s.size(); en++) {
            mp[s[en]]++;
            
            while(mp[s[en]] > 1) {
                mp[s[st]]--;
                st++;
            }

            mx = max(mx,en-st+1);
        }
        return mx;
        
    }
};
