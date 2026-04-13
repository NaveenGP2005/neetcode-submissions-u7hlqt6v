class Solution {
public:
    vector<vector<int>>memo;
    bool f(string s1,string s2,string s3,int i,int j){
        int m=s1.size(),n=s2.size(),k=i+j;
        if(i==m&&j==n&&k==s3.size()) return 1;
        if(memo[i][j]!=-1) return memo[i][j];
        bool a=(i<m&&s1[i]==s3[k])&&f(s1,s2,s3,i+1,j);
        bool b=(j<n&&s2[j]==s3[k])&&f(s1,s2,s3,i,j+1);
        return memo[i][j]=a||b;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return 0;
        memo.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return f(s1,s2,s3,0,0);
    }
};
