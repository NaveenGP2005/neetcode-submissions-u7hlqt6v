class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        int ans=-1;
        for(int i=1;i<=n-1;i++){
            vector<int>temp=dist;
        for(auto&it:times){
            int u=it[0],v=it[1],t=it[2];
            if(dist[u]!=INT_MAX&&dist[u]+t<temp[v]) temp[v]=t+dist[u];
        }
        dist=temp;
        }

        for(int i=1;i<=n;i++){
            if(dist[i]!=INT_MAX) ans=max(ans,dist[i]);
            else return -1;
        }
        return ans;
    }
};
