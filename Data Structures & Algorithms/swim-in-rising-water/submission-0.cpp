class Solution {
public:
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    int n;
    bool poss(vector<vector<int>>& grid,int i,int j,int t,vector<vector<bool>>&vis){
        if(i<0||i>=n||j<0||j>=n||grid[i][j]>t||vis[i][j]) return 0;

        vis[i][j]=1;
        if(i==n-1&&j==n-1) return 1;

        for(auto&it:dir){
            int ni=i+it[0],nj=j+it[1];
            if(poss(grid,ni,nj,t,vis)) return 1;
        }
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
         n=grid.size();
        int res=0,l=grid[0][0],r=n*n-1;
        while(l<=r){
        vector<vector<bool>>vis(n,vector<bool>(n,0));
            int mid=l+(r-l)/2;
            if(poss(grid,0,0,mid,vis)){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};
