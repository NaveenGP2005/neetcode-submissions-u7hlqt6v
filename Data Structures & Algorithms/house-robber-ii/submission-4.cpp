class Solution {
public:
    vector<vector<int>>memo;
    int rob(vector<int>& nums) {
        int n=nums.size();
        memo.resize(n,vector<int>(2,-1));
        if(n==1) return nums[0];
        return max(f(0,1,nums),f(1,0,nums));
    }

    int f(int i,bool flag,vector<int>&nums){
        if(i>=nums.size()||(flag&&i==nums.size()-1)) return 0;
        if(memo[i][flag]!=-1) return memo[i][flag];
        memo[i][flag]=max(nums[i]+f(i+2,flag|i==0?1:0,nums),f(i+1,flag,nums));
        return memo[i][flag]; 
    }
};
