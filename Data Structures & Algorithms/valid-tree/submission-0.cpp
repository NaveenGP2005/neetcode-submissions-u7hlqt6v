class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
       if(edges.size()!=n-1) return 0;
       vector<vector<int>>adj(n);
       for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0])
       ;}      
       vector<bool>vis(n,0);
       queue<int>q;
       q.push(0);
       vis[0]=1;
       int cnt=0;
       while(q.size()){
        int f=q.front();q.pop();
           cnt++;
           for(auto it:adj[f]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
           }
       }
       return cnt==n;
    }
};
