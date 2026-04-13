class Solution {
public:
    int climbStairs(int n) {
        if(n<=3) return n;
        int curr=0,prev1=3,prev2=2;
            for(int i=3;i<n;i++) {
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};
