class Solution {
public:
    int m,n;
    vector<vector<int>>memo;
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool safe(int i,int j){
        return i<m&&i>=0&&j<n&&j>=0;
    }
    int dfs(vector<vector<int>>&mat,int i,int j){
        int ans=1;
        if(memo[i][j]!=-1) return memo[i][j];
        for(auto&it:dir){
            int ni=it[0]+i,nj=it[1]+j;
            if(safe(ni,nj)&&mat[ni][nj]<mat[i][j]) ans=max(ans,1+dfs(mat,ni,nj));
        }
        return memo[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        m=mat.size(),n=mat[0].size();
        memo.resize(m+1,vector<int>(n+1,-1));
        int res=0;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        res=max(res,dfs(mat,i,j));

        return res;
    }
};
