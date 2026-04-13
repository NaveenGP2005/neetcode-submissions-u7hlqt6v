class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e8);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=dist;
            for(auto&it:flights){
                int u=it[0],v=it[1],cost=it[2];
                if(dist[u]!=1e8&&dist[u]+cost<temp[v]) temp[v]=dist[u]+cost;
            }
            dist=temp;
        }
        return dist[dst]==1e8?-1:dist[dst];
    }
};
