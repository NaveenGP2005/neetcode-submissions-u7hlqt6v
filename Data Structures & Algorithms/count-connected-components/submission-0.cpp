class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        int cnt=0;

        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
          if(!vis[i]) cnt++;

          queue<int>q;
          q.push(i);
          vis[i]=1;
          while(q.size()){
            int f=q.front();q.pop();
            for(auto it:adj[f]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
          }
        }
        return cnt;
    }
};
