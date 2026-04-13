class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({s,1});
        while(q.size()){
            string f=q.front().first;
            int l=q.front().second;
            q.pop();
            if(f==e) return l;
            for(int i=0;i<wordList.size();i++){
                char og=f[i];
                for(char c='a';c<='z';c++){
                    f[i]=c;
                    if(st.count(f)){
                       q.push({f,l+1});
                       st.erase(f);
                    }
                }
                f[i]=og;
            }
        }
        return 0;
    }
};
