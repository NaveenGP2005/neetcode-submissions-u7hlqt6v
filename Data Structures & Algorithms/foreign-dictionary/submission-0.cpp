class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<bool> present(26, false);

        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = true;

        for (int i = 0; i + 1 < words.size(); i++) {
            string &s1 = words[i];
            string &s2 = words[i + 1];
            int j = 0, l1 = s1.size(), l2 = s2.size();

            while (j < l1 && j < l2 && s1[j] == s2[j]) j++;

            if (j == min(l1, l2) && l1 > l2)
                return "";

            if (j < l1 && j < l2) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                indeg[s2[j] - 'a']++;
            }
        }

        queue<int> q;
        int total = 0;

        for (int i = 0; i < 26; i++) {
            if (present[i]) {
                total++;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }

        string ans = "";
        while (!q.empty()) {
            int f = q.front(); q.pop();
            ans += char(f + 'a');

            for (int it : adj[f]) {
                if (--indeg[it] == 0)
                    q.push(it);
            }
        }

        return ans.size() == total ? ans : "";
    }
};
