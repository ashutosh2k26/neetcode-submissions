class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> ret(temperatures.size(),0);

        for(int i = 0 ; i < temperatures.size(); i++) {
            if(stk.empty() || (temperatures[i] < temperatures[stk.top()])) {
                stk.push(i);
            } else {
                while(!stk.empty() && (temperatures[stk.top()] < temperatures[i])){
                    int curr = stk.top();
                    stk.pop();
                    ret[curr] = i - curr;
                    std::cout<<" curr "<<curr<<" temp[curr] "<<temperatures[curr]<<" ret"<<(i-curr)<<"\n";
                }
                stk.push(i);
            }
        }
        return ret; 
    }
};
