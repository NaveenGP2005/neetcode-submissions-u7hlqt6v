class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n=p.size();
        vector<pair<int,int>>cars(n);
        for(int i=0;i<n;i++) cars[i]={p[i],s[i]};
        sort(cars.begin(), cars.end(), [&](auto &a, auto &b){
            return a.first > b.first;
        });

        stack<double>st;
        for(auto &c:cars){
            auto [f,s]=c;
            double time=(target-f)*1.0/s;

            if(st.empty()||time>st.top()) st.push(time);
        }
        return st.size();
    }
};
