class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int x) {
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(x-nums[i])!=mp.end()) return {mp[x-nums[i]],i};
              mp[nums[i]]=i;
        }
        return {};
    }
};
