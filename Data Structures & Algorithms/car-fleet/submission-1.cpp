class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for (int i = 0; i < n; i++)
            cars[i] = { position[i], speed[i] };

        // sort by position descending (rightmost first)
        sort(cars.begin(), cars.end(), [&](auto &a, auto &b){
            return a.first > b.first;
        });

        stack<double> st;     // stack stores times to reach target

        for (auto &c : cars) {
            double pos = c.first;
            double spd = c.second;

            double time = (target - pos) * 1.0 / spd;

            // if time is greater than the top of stack → new fleet
            // otherwise it joins existing fleet
            if (st.empty() || time > st.top())
                st.push(time);
        }

        return st.size();   // number of fleets
    }
};
