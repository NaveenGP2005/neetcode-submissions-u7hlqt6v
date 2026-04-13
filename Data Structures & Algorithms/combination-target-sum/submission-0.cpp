class Solution {
public:
void fs(int idx,int t,vector<int>&a,vector<int>&ds,vector<vector<int>>&ans){
       if(a.size()==idx){
        if(t==0) ans.push_back(ds);
        return;
       }

       if(a[idx]<=t){
         ds.push_back(a[idx]);
         fs(idx,t-a[idx],a,ds,ans);
         ds.pop_back();
       }
       fs(idx+1,t,a,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<vector<int>>ans;
        vector<int>ds;
        fs(0,t,a,ds,ans);
        return ans;
    }
};
