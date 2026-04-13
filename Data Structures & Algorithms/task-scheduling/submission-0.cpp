class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>f(26,0);
        priority_queue<int>mh;

        for(char c:tasks) f[c-'A']++;
        int time=0;
        for(int t:f) 
        if(t!=0)
        mh.push(t);

        while(mh.size()){
          vector<int>temp;

          for(int i=1;i<=n+1;i++){

            if(mh.size()){
                int t=mh.top()-1;
                mh.pop();
                temp.push_back(t);
            }
          }

          for(int t:temp) 
          if(t!=0)
          mh.push(t);

          if(mh.size()) time+=n+1;
          else time+=temp.size();
        }
        return time;
    }
};
