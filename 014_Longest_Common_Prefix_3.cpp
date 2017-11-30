class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = helper(strs, 0, strs.size() - 1, strs[0].size());
        return strs[0].substr(0, n);
    }
    int helper(vector<string>& strs, int l, int r, int n) {
        if (l == r) return strs[l].size();
        int mid = (l + r) / 2;
        int m1 = helper(strs, l, mid, n);
        int m2 = helper(strs, mid + 1, r, n);
        int m = min(m1, m2);
        for (int i = 0; i < m; ++i) {
            if (strs[l][i] != strs[r][i]) return i;
        }
        return m;
    }
};