class KthLargest {
public:
    int K;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(int &n:nums){
            pq.push(n);
            if(pq.size()>k) pq.pop();
        }
        K=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        return pq.top();
    }
};
