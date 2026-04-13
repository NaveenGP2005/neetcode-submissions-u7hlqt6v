class Solution {
public:
    void fc(int idx, int t, vector<int> &c, vector<int> &ds, vector<vector<int>> &ans) {
        if (idx == (int)c.size()) {
            if (t == 0) ans.push_back(ds);
            return;
        }

        // TAKE current element ONCE (note: idx+1, not idx)
        if (c[idx] <= t) {
            ds.push_back(c[idx]);
            fc(idx + 1, t - c[idx], c, ds, ans);
            ds.pop_back();
        }

        // SKIP all duplicates of c[idx] in one shot
        int j = idx + 1;
        while (j < (int)c.size() && c[j] == c[idx]) j++;
        fc(j, t, c, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(c.begin(), c.end());  // important for handling duplicates
        fc(0, t, c, ds, ans);
        return ans;
    }
};
