class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, 0, "", res);
        return res;
    }
    void helper(int n, int m, string s, vector<string>& res) {
        if (n == 0 && m == 0) {
            res.push_back(s);
            return;
        }
        if (n > 0) helper(n - 1, m + 1, s + '(', res);
        if (m > 0) helper(n, m - 1, s + ')', res);
    }
};