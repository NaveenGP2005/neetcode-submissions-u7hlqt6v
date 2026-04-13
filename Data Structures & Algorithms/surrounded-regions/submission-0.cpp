class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<char>>ans(m,vector<char>(n,'X'));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                    q.push({i,j});
                    ans[i][j]='O';
                    board[i][j]='X';
                }
            }
        }
        int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
        while(q.size()){
            auto[f,s]=q.front();q.pop();
             for(int i=0;i<4;i++){
                int nr=f+dr[i];
                int nc=s+dc[i];
                if((nr>=0&&nr<m-1&&nc>=0&&nc<n-1) && board[nr][nc]=='O'){
                    q.push({nr,nc});
                    ans[nr][nc]='O';
                    board[nr][nc]='X';
                }
             }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};
