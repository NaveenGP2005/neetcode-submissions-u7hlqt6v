class Solution {
public:
typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp(nums.size());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        for(auto it:mp){
            int f=it.second,val=it.first;
            pq.push({f,val});

            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second)
            ;pq.pop();
        }return ans;
    }
};
