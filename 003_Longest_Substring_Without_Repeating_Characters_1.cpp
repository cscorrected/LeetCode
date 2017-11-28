class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int lmax = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, m[s[i]]);
            lmax = max(lmax, i - start + 1);
            m[s[i]] = i + 1;
        }
        return lmax;
    }
};