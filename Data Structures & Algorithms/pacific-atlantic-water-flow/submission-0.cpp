class Solution {
public:
    void dfs(vector<vector<int>>& heights,int r,int c,int prev,vector<vector<bool>>&s){
        int m=heights.size(),n=heights[0].size();
        int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
                if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (s[r][c]) return;
        if (heights[r][c] < prev) return;
        s[r][c]=1;
        for(int i=0;i<4;i++){
            int i_=r+dr[i],j_=c+dc[i];
            dfs(heights,i_,j_,heights[r][c],s);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>>p(m,vector<bool>(n,0));
        vector<vector<bool>>a(m,vector<bool>(n,0));

        for(int i=0;i<n;i++){
            dfs(heights,0,i,INT_MIN,p);
            dfs(heights,m-1,i,INT_MIN,a);
        }

        for(int i=0;i<m;i++){
            dfs(heights,i,0,INT_MIN,p);
            dfs(heights,i,n-1,INT_MIN,a);
        }

        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(p[i][j]&&a[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
