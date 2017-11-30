class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int n = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == strs[i].size() || strs[i][j] != strs[0][j]) {
                    n = j;
                    break;
                }
            }
            if (n == 0) return "";
        }
        return strs[0].substr(0, n);
    }
};