class Solution {
public:

    bool isAnagram(string s, string t) {
        vector<int> f(26, 0);
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            f[s[i] - 'a']++;
            f[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (f[i] != 0) return false;
        }
        return true;
    }


    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
        vector<bool>v(str.size(),0);
        for(int i=0;i<str.size();i++){
            vector<string>res;
            if(v[i])continue;
            res.push_back(str[i]);
            v[i]=1;
            for(int j=i+1;j<str.size();j++){
                if(isAnagram(str[i],str[j])){
                     res.push_back(str[j]);
                     v[j]=1;
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
