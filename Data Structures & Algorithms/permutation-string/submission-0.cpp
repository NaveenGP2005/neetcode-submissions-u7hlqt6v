class Solution {
public:
    bool isFsame(int f1[],int f2[]){
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        if(n1>n2) return false;
        int f[26]={0};
        for(int i=0;i<n1;i++) f[s1[i]-'a']++;
        int wsize=n1;
        for(int i=0;i<n2;i++){
            int widx=0;
            int wf[26]={0};
            while(widx<n2&&widx<wsize){
                wf[s2[widx+i]-'a']++;
                 widx++;
            }
            if(isFsame(wf,f)) return true;
        }
        return false;
    }
};
