class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i=0,j=0,size=arr.size();
        vector<int>ans(size-k+1);
        deque<int>dq;
        while(j<size){
            while(dq.size()&&dq.back()<arr[j]){
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if(j-i+1<k) j++;
            else if(j-i+1==k){
             ans[i]=dq.front();
             if(dq.front()==arr[i]) dq.pop_front();
             i++;
             j++;
            }
        }
        return ans;
    }
};
