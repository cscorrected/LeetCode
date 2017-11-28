class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> v(128);
        int lmax = 0, start = 0;
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, v[s[i]]);
            lmax = max(lmax, i - start + 1);
            v[s[i]] = i + 1;
        }
        return lmax;
    }
};