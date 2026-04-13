class Solution {
public:
   int sos(int n){
    int ans=0;
    while(n){
        int d=n%10;
        ans+=(d*d);
        n/=10;
    }
    return ans;
   }
    bool isHappy(int n) {
        unordered_set<int>mp;
        while(mp.find(n)==mp.end()){
            mp.insert(n);
            n=sos(n);
            if(n==1) return 1;
        }
        return 0;
    }
};
