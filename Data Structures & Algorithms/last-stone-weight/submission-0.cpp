class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>mh;
        for(int s:stones) mh.push(s);
        while(mh.size()>1){
              int f=mh.top();mh.pop();
              int s=mh.top();mh.pop();
              if(f>s) mh.push(f-s);
        }
        mh.push(0);
        return mh.top();
    }
};
