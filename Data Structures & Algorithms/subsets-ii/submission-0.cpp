class Solution {
public:
void fs(int idx,vector<int>&a,vector<int>&ds,vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=idx;i<a.size();i++){
        if(i!=idx&&a[i]==a[i-1]) continue;
        ds.push_back(a[i]);
        fs(i+1,a,ds,ans);
        ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
         vector<vector<int>>ans;
        vector<int>ds;
        sort(a.begin(),a.end());
        fs(0,a,ds,ans);
        return ans;
    }
};