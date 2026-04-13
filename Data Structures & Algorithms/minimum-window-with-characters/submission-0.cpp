class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(char c:t) mp[c]++;
        int minl=INT_MAX;
        int i=0,j=0,n=s.size(),start=0;
        int count=mp.size();
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;
            }if(count==0){
                while(count==0){
                    if(j-i+1<minl){
                        start=i;
                        minl=j-i+1;
                    }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++;
                }
                i++;
                }
            }
            j++;
        }

        if(minl==INT_MAX) return "";
        return s.substr(start,minl);
    }
};
