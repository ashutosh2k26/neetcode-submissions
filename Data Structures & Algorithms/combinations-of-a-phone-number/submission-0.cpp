class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return ret;
        
        dgt = digits;
        len = digits.size();
        string path = "";
        int index = 0;        
        LetterCom(index,path);
        return ret;
    }
private:
    void LetterCom(int index,string path) {
        if(index == len) {
            ret.push_back(path);
        }

        auto itr = mp.find(dgt[index]);
        if( itr != mp.end()) {
            for( auto it : itr->second) {
                LetterCom(index+1,path+it);
            }
        }
    }
    map<char,vector<char>> mp {
        {'2', {'a','b','c'}},
        {'3', {'d','e','f'}},
        {'4', {'g','h','i'}},
        {'5', {'j','k','l'}},
        {'6', {'m','n','o'}},
        {'7', {'p','q','r','s'}},
        {'8', {'t','u','v' }},
        {'9', {'w','x','y','z'}}
    };
    string dgt;
    int len;
    vector<string> ret;

};
