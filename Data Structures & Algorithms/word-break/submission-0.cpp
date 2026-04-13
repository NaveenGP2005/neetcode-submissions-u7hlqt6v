class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int maxLen = 0;
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.length());
        }
        unordered_map<int, bool> memo;
        return canBreak(0, s, dict, memo, maxLen);
    }

    bool canBreak(int start, string &s, unordered_set<string> &dict, unordered_map<int, bool> &memo, int maxLen) {
        if (start == s.length()) return true;
        if (memo.count(start)) return memo[start];

        for (int end = start + 1; end <= min((int)s.length(), start + maxLen); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && canBreak(end, s, dict, memo, maxLen)) {
                return memo[start] = true;
            }
        }

        return memo[start] = false;
    }
};