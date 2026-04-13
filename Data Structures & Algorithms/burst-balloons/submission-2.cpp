class Solution {
public:
vector<vector<int>>dp;
    int f(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=INT_MIN;
        for(int idx=i;idx<=j;idx++){
        int cost=nums[i-1]*nums[idx]*nums[j+1]+f(i,idx-1,nums)+f(idx+1,j,nums);
        mx=max(mx,cost);
        }
        return dp[i][j]=mx;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return f(1,nums.size()-2,nums);
    }
};
