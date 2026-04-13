class Solution {
public:
        vector<string>res={"JFK"};
        int ts=0;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        ts=tickets.size()+1;
        for(auto&it:tickets) adj[it[0]].push_back(it[1]);
        for(auto&it:adj) sort(it.second.begin(),it.second.end());
        dfs("JFK",adj);
        return res;
    }

    bool dfs(string src,unordered_map<string,vector<string>>&adj){
            if(res.size()==ts) return 1;
            if(adj.find(src)==adj.end()) return 0;

            for(int i=0;i<adj[src].size();i++){
                string next=adj[src][i];
                adj[src].erase(adj[src].begin()+i);
                res.push_back(next);

                if(dfs(next,adj)) return 1;

                res.pop_back();
                adj[src].insert(adj[src].begin()+i,next);
            }
            return 0;
    }
};
