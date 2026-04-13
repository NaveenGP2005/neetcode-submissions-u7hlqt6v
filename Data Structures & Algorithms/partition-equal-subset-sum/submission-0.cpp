class Solution {
public:
    vector<vector<bool>>memo;
    void subsetsum(vector<int>&nums,int sum){
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum;j++)
            if(nums[i-1]<=j){
              memo[i][j]=memo[i-1][j]||memo[i-1][j-nums[i-1]];
            }
            else memo[i][j]=memo[i-1][j];
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2) return 0;
        memo.resize(n+1,vector<bool>(sum/2+1,0));
        for(int i=0;i<=n;i++) memo[i][0]=1;
        subsetsum(nums,sum/2);
        return memo[n][sum/2];
    }
};
