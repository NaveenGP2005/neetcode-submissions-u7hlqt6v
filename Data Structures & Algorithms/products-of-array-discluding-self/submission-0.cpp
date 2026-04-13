class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int>pm(nums.size());
       for(int i=0;i<nums.size();i++){
      pm[i]=1;
        for(int j=0;j<nums.size();j++){
            if(i!=j) pm[i]*=nums[j];
        }
       }
      return pm;
    }
};
