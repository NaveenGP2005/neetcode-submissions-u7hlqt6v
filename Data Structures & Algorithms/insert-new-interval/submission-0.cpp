class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        int i=0,n=intervals.size();
        vector<vector<int>>res;
        while(i<n&&intervals[i][1]<ni[0]){
            res.push_back(intervals[i++]);
        }

        while(i<n&&intervals[i][0]<=ni[1]){
            ni[0]=min(intervals[i][0],ni[0]);
            ni[1]=max(intervals[i][1],ni[1]);
            i++;
        }

        res.push_back(ni);

        while(i<n) res.push_back(intervals[i++]);
        return res;
    }
};
