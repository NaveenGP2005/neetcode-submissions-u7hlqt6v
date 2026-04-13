class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         unordered_map<char,int>mp;
         int i=0,j=0,size=s.length(),mx=0;
           while (j < size) {
            if (mp[s[j]] == 0) {       // char not in current window
                mp[s[j]]++;            // include s[j]
                mx = max(mx, j - i + 1);
                j++;                   // expand
            } else {
                // char s[j] is already in window -> shrink from left
                mp[s[i]]--;
                i++;
            }
        }
         return mx;
    }
};
