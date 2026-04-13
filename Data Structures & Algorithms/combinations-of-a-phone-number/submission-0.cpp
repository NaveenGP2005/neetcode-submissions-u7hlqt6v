class Solution {
public:
    string digits;                 
    vector<string> res;             
    string temp;              
    unordered_map<char,string> mp; 

    void fs(int idx){
        if(idx>=digits.length()){
            res.push_back(temp);
            return;
        }
        char ch=digits[idx];
        string str=mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            fs(idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        this->digits = digits;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        fs(0);
        return res;
    }
};
