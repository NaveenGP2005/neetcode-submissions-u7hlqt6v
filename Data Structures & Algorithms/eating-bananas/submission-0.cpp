class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1,end=0;
        for(int p:piles) end=max(end,p);
        int ans=end;
        while(start<=end){
            int mid=start+(end-start)/2;
            int time=0;
            for(int p:piles) time+=(p+mid-1)/mid;
            if(time<=h){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};
