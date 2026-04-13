class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>mh;
        for(auto&it:points){
            int dist=it[0]*it[0]+it[1]*it[1];
            mh.push({dist,{it[0],it[1]}});
            if(mh.size()>k) mh.pop();
        }

        vector<vector<int>>res;
        while(mh.size()){
            res.push_back({mh.top().second.first,mh.top().second.second});
            mh.pop();
        }
        return res;
    }
};
