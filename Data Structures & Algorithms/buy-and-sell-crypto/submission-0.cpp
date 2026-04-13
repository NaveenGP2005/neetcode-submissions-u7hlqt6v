class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ms=0,mini=prices[0];
        for(int i=1;i<prices.size();i++){
            int cost=prices[i]-mini;
            ms=max(ms,cost);
            mini=min(mini,prices[i]);
        }
        return ms;
    }
};
