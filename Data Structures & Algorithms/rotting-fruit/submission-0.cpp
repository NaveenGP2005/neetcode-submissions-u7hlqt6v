class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int fresh=0,time=0,rt=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1) fresh++;
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(q.size()){
            auto p=q.front();q.pop();
            int r=p.first.first,c=p.first.second,t=p.second;
            time=max(time,t);
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    int nr=r+dr[i],nc=c+dc[i];
                    if(nr>=0&&nc>=0&&nr<m&&nc<n&&vis[nr][nc]!=2&&grid[nr][nc]==1){
                        q.push({{nr,nc},t+1});
                        vis[nr][nc]=2;
                        rt++;
                    }
                }
            }
        }
        if(rt!=fresh) return -1;
        return time;
    }
};
