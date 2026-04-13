class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0,far=0,cur=0;
        for(int i=0;i<n-1;i++){
            far=max(far,i+nums[i]);
            if(i==cur){
                jumps++;
                cur=far;

                if(cur>=n-1) break;
            }
        }
        return jumps;
    }
};
