class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int start = 0, lmax = 1;
        for (int i = 0; i < s.size(); ) {
            int j = i - 1, k = i + 1;
            while (k < s.size() && s[k] == s[k - 1]) {
                ++k;
            }
            i = k;
            while (j >= 0 && k < s.size() && s[j] == s[k]) {
                --j;
                ++k;
            }
            int l = k - j - 1;
            if (l > lmax) {
                lmax = l;
                start = j + 1;
            }
        }
        return s.substr(start, lmax);
    }
};