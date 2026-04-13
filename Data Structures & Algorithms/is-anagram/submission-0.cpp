class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>f(26,0);
        int n1=s.length(),n2=t.length();
        if(n1!=n2) return false;
        for(int i=0;i<n1;i++){
            f[s[i]-'a']++;
            f[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(f[i]!=0) return false;
        }
        return true;
    }
};
