class Solution {
public:
    int help(int n){
        int ones=0;
        while(n){
            ones+=n&1;
            n>>=1;
        }
        return ones;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++) ans[i]=help(i);
        return ans;
    }
};
