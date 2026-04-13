class Solution {
public:
vector<vector<string>>res;
int N;
    bool iv(vector<string>&b,int row,int col){
        for(int i=row-1;i>=0;i--){
            if(b[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(b[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<N;i--,j++){
            if(b[i][j]=='Q') return false;
        }
        return true;
    }
    void fs(vector<string>&b,int row){
        if(row>=N){
            res.push_back(b);
            return;
        }

        for(int col=0;col<N;col++){
            if(iv(b,row,col)){
                b[row][col]='Q';
                fs(b,row+1);
                b[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> b(n,string(n,'.'));
        N=n;
        fs(b,0);
        return res;
    }
};
