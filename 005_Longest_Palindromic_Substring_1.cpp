class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) return s;
        int start = 0, lmax = 1;
        for (int i = 0; i < s.size(); ++i) {
            extend(s, i, i, start, lmax);
            extend(s, i, i + 1, start, lmax);
        }
        return s.substr(start, lmax);
    }
    void extend(string s, int j, int k, int& start, int& lmax) {
        if (j > k) return;
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
};