class Solution {
public:
    bool isMatch(string s, string p) {
        return helper(s, p, 0, 0);
    }
    bool helper(const string& s, const string& p, int i, int j) {
        if (j == p.size()) return i == s.size();
        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
        if (j + 1 < p.size() && p[j + 1] == '*') {
            return helper(s, p, i, j + 2) || (firstMatch && helper(s, p, i + 1, j));
        } else {
            return firstMatch && helper(s, p, i + 1, j + 1);
        }
    }
};