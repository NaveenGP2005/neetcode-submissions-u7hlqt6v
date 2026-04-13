class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize) return 0;
        map<int,int>mp;
        for(auto &it:hand) mp[it]++;
        while(!mp.empty()){
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0) return 0;
                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        return 1;
    }
};
