class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& t) {
        unordered_set<int>ans;
        for(auto &it:triplets){
            if(it[0]>t[0]||it[1]>t[1]||it[2]>t[2]) continue;
            for(int i=0;i<3;i++){
                if(it[i]==t[i]) ans.insert(i);
            }
        }
        return ans.size()==3;
    }
};
