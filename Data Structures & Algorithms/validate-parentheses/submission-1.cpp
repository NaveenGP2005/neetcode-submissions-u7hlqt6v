class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()) return 0;
                char t=st.top();
                st.pop();
                if(s[i]==')'&& t!='('||s[i]=='}'&&t!='{'||s[i]==']'&&t!='[') return 0;
            }
        }
        return st.empty();
    }
};
