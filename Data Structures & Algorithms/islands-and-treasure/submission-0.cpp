class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }

        int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
        while(q.size()){
            auto[f,s]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                    int nr=f+dr[i],nc=s+dc[i];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==2147483647){
                        grid[nr][nc]=grid[f][s]+1;
                        q.push({nr,nc});
                    }
            }
        }
    }
};
