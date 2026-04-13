class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> ans(nums.begin(),nums.end());
        return nums.size()!=ans.size();
    }
};