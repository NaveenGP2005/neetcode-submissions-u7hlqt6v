class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        if(in.empty()) return {};
          sort(in.begin(), in.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });
        vector<vector<int>>ans;
        for(int i=0;i<in.size();i++){
            if(ans.empty()||in[i][0]>ans.back()[1]) ans.push_back(in[i]);
            else{
                auto &it=ans.back();
              
                    it[1]=max(it[1],in[i][1]);
                
            }
        }
        return ans;
    }
};
