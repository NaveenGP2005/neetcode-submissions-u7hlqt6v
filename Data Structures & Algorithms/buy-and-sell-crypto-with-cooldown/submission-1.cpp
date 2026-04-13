class Solution {
public:
vector<vector<int>>memo;
    int solve(vector<int>&p,int day,int n,bool buy){
        if(day>=n) return 0;
        if(memo[day][buy]!=-1) return memo[day][buy];
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
        return memo[day][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size(),vector<int>(2,-1));
        return solve(prices,0,prices.size(),true);
    }
};
