class Solution {
public:
vector<vector<int>>memo;
    int subsum(vector<int>&nums,int sum){
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=sum;j++){
                if(nums[i-1]<=j) memo[i][j]=memo[i-1][j]+memo[i-1][j-nums[i-1]];
                else memo[i][j]=memo[i-1][j];
            }
        }
        return memo[nums.size()][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if((sum+target)%2!=0||target>sum) return 0;

        memo.resize(nums.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<nums.size();i++) memo[i][0]=1;

        return subsum(nums,(sum+target)/2);
    }
};
