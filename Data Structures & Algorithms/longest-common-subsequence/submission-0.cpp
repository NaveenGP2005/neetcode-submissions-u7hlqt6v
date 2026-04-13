class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        vector<vector<int>>memo(s.size()+1,vector<int>(t.size()+1,0));
          
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<t.size()+1;j++){
                if(s[i-1]==t[j-1]) memo[i][j]=1+memo[i-1][j-1];
                else memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
            }
        }
        return memo[s.size()][t.size()];
    }
};
