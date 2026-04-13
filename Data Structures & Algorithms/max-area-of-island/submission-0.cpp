class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&vis,int &ans){
        int m=grid.size(),n=grid[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({row,col});
        while(q.size()){
        ans++;
            int f=q.front().first,s=q.front().second;
            q.pop();
            vis[f][s]=1;
            for(int i=0;i<4;i++){
               
                    int nr=f+drow[i];
                    int nc=s+dcol[i];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]&&grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mans=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]==1){
                    int ans=0;
                bfs(i,j,grid,vis,ans);
                mans=max(mans,ans);
                }
                
            }
        }
        return mans;
    }
};
