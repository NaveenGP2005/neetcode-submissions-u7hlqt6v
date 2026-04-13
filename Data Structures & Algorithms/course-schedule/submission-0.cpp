class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ans,ind(numCourses, 0);
        
        for(auto&pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
            ind[pre[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }

        while(q.size()){
            int node=q.front();q.pop();
            ans.push_back(node);
            for(int&n:adj[node]){
                ind[n]--;
                if(ind[n]==0)
                    q.push(n);
            }
        }
        return ans.size()==numCourses;
    }
};