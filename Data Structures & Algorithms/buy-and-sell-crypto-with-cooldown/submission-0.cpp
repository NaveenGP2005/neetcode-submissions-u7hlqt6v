class Solution {
public:
    int solve(vector<int>&p,int day,int n,bool buy){
        if(day>=n) return 0;
        int profit=0;
        if(buy){
            int take=solve(p,day+1,n,0)-p[day];
            int not_take=solve(p,day+1,n,1);
            profit=max({take,not_take,profit});
        }
        else{
            int sell=p[day]+solve(p,day+2,n,1);
            int not_sell=solve(p,day+1,n,0);
            profit=max({profit,sell,not_sell});
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(prices,0,prices.size(),true);
    }
};
