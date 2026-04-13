class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        string pal="",maxl="";
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            start=i,end=i;
            while((start>=0&&end<s.length())&&(s[start]==s[end])) start--,end++;
            pal=s.substr(start+1,end-start-1);
            if(pal.length()>maxl.length()) maxl=pal;

            start=i,end=i+1;
            while((start>=0&&end<s.length())&&(s[start]==s[end])) start--,end++;
            pal=s.substr(start+1,end-start-1);
            if(pal.length()>maxl.length()) maxl=pal;
        }
        return maxl;
    }
};
