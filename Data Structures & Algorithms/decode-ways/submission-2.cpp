class Solution {
public:
vector<int>dp;
    int solve(string s,int idx){
        if(idx>=s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take1=solve(s,idx+1);
        int take2=0;
        if(idx+1<s.size()&&(s[idx]=='1'||(s[idx]=='2'&&s[idx+1]<='6')))
        take2=solve(s,idx+2);

        return dp[idx]=take1+take2;

    }
    int numDecodings(string s) {
        dp.resize(s.size(),-1);
        return solve(s,0);
    }
};
