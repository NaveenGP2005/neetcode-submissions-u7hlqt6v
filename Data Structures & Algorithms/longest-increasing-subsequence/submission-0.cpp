class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n);

        for(int i=1;i<nums.size();i++)
        {
         for(int j=0;j<i;j++)
         {
            if(nums[i]>nums[j]){
                if(a[j]+1>a[i]) a[i]=a[j]+1;
            }
         }
        }
        int ans=0;
        for(int aa:a) ans=max(ans,aa);
        return ans+1;
    }
};
