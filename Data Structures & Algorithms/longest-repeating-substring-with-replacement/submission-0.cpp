class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0,i=0,n=s.length();
        int f[26]={0};
        int ans=0,maxf=0;
        while(j<n){
            f[s[j]-'A']++;
            maxf=max(maxf,f[s[j]-'A']);
            if((j-i+1)-maxf>k){
                f[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
