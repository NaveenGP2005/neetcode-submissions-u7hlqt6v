class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s = "";

        for (int d : digits) {
            s.push_back(char(d + '0'));
        }
  long long num = stoll(s);
        num += 1;

        vector<int> ans;
        while (num > 0) {
            ans.push_back(num % 10);
            num /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};