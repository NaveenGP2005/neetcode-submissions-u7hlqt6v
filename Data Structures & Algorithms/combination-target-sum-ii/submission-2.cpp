class Solution {
public:
    void fs(int idx,int t,vector<int>&a,vector<int>&ds,vector<vector<int>>&ans){
        if(a.size()==idx){
            if(t==0) ans.push_back(ds);
return;
        }
        if(a[idx]<=t){
            ds.push_back(a[idx]);
            fs(idx+1,t-a[idx],a,ds,ans);
            ds.pop_back();
        }
        int j=idx+1;
        while(j<a.size()&&a[j]==a[idx]) j++;
        fs(j,t,a,ds,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        fs(0,t,a,ds,ans);
        return ans;
    }
};
