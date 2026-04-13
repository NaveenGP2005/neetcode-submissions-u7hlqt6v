class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lp=1,rp=1,ans=nums[0];
        for(int i=0;i<nums.size();i++){
            lp=lp==0?1:lp;
            rp=lp==0?1:rp;
            lp*=nums[i];
            rp*=nums[nums.size()-i-1];
            ans=max(ans,max(lp,rp));
        }
        return ans;
    }
};
