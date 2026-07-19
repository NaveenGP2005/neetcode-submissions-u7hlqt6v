class Solution {
public:


    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<str.size();i++){
            string sorted=str[i];
            sort(sorted.begin(),sorted.end());
            mp[sorted].push_back(str[i]);
        }

        for(auto s:mp) ans.push_back(s.second);
        return ans;
    }
};
