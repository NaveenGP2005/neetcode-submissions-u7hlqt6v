class Solution {
public:
    vector<vector<int>>memo;
    bool f(int i,int j,string s,string p){
        if(j==p.length()) return i==s.length();
        bool matched=0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(i<s.length()&&(s[i]==p[j]||p[j]=='.')) matched=1;

        if(j+1<p.length()&&(p[j+1]=='*')){
            bool not_take=f(i,j+2,s,p);
            bool take=matched&&f(i+1,j,s,p);
            return memo[i][j]=take||not_take;
        }

        return memo[i][j]=matched&&f(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memo.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return f(0,0,s,p);
    }
};
