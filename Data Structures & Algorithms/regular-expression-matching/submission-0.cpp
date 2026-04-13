class Solution {
public:

    bool f(int i,int j,string s,string p){
        if(j==p.length()) return i==s.length();
        bool matched=0;
        if(i<s.length()&&(s[i]==p[j]||p[j]=='.')) matched=1;

        if(p[j+1]=='*'){
            bool not_take=f(i,j+2,s,p);
            bool take=matched&&f(i+1,j,s,p);
            return take||not_take;
        }

        return matched&&f(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        return f(0,0,s,p);
    }
};
