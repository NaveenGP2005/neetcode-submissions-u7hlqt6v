class Solution {
public:
    bool detect(int src,vector<vector<int>>&adj,vector<bool>&vis){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(q.size()){
            int node=q.front().first,parent=q.front().second;
            q.pop();
            for(auto &it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return 1;
                }
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(auto&it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            vector<bool>vis(n+1,0);
            if(detect(it[0],adj,vis)){
                return it;
            }
        }
        return {};
    }
};
