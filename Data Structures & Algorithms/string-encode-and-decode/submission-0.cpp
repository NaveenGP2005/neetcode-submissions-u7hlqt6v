#include<string>
class Solution {
public:

    string encode(vector<string>& strs) {
           string en="";
           for(string &s:strs) en+=to_string(s.size())+"#"+s;
           return en;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!='#') j++;
            int len=stoi(s.substr(i,j-i));
            string w=s.substr(j+1,len);
            ans.push_back(w);
            i=j+1+len;
        }
        return ans;
    }
};
