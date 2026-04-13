class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st;
        int n=h.size();
        if(n==0) return 0;
        vector<int>l(n),r(n);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0&&h[st.top()]>=h[i]) st.pop();
            r[i]=st.empty()?n:st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i]) st.pop();
            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int area=h[i]*(r[i]-l[i]-1);
            ans=max(ans,area);
        }
        return ans;
    }
};
