class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()<=1) return 1;
        int res=0;
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            start=i,end=i;
            while((start>=0&&end<s.length())&&(s[start]==s[end])) res++,start--,end++;

            start=i,end=i+1;
            while((start>=0&&end<s.length())&&(s[start]==s[end])) res++,start--,end++;
        }
        return res;
    }
};
