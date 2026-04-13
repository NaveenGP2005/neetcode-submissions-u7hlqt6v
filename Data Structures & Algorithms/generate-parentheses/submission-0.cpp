class Solution {
public:
vector<string>ans;
    void fs(string &s,int n,int open,int close){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n){
            s.push_back('(');
            fs(s,n,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            fs(s,n,open,close+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0,close=0;
        fs(curr,n,open,close);
        return ans;
    }
};
