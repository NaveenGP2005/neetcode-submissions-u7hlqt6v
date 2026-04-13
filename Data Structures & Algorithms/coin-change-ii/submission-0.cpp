class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>memo(coins.size()+1,vector<int>(amount+1,0));
        for(int i=0;i<=coins.size();i++) memo[i][0]=1;

        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) memo[i][j]=memo[i][j-coins[i-1]]+memo[i-1][j];
                else memo[i][j]=memo[i-1][j];
            }
        }
        return memo[coins.size()][amount];
    }
};
