class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={0},col[9][9]={0},box[9][9]={0};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c=='.') continue;

                int d=c-'1';
                int bI=(i/3)*3+(j/3);

                if(row[i][d]||col[j][d]||box[bI][d]) return 0;

                row[i][d]=col[j][d]=box[bI][d]=1;
            }
        }
        return 1;
    }
};
