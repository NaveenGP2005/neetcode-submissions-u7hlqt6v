class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>>memo(s.size()+1,vector<int>(t.size()+1,0));
          for(int i=0;i<=s.size();i++) memo[i][0]=1;
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<t.size()+1;j++){
                if(s[i-1]==t[j-1]) memo[i][j]=memo[i-1][j]+memo[i-1][j-1];
                else memo[i][j]=memo[i-1][j];
            }
        }
        return memo[s.size()][t.size()];
    }
};
