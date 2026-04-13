class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>res;
        unordered_map<int,int>mp;

        for(int i=0;i<s.size();i++) mp[s[i]-'a']=i;

        int i=0,start=0,end=0;
        while(i<s.size()){
            end=max(end,(mp[s[i]-'a']));
            if(i==end){
                res.push_back(end-start+1);
                start=end+1;
            }
            i++;
        }
        return res;
    }
};
