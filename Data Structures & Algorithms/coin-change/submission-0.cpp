class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>memo(coins.size()+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++) memo[0][i]=INT_MAX-1;

        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j) memo[i][j]=min(memo[i][j-coins[i-1]]+1,memo[i-1][j]);
                else memo[i][j]=memo[i-1][j];
            }
        }
        return memo[coins.size()][amount]==INT_MAX-1?-1:memo[coins.size()][amount];
    }
};
